
void uva_11503(){
    int test_cases;
    std::cin >> test_cases;

    for(int tc = 0; tc < test_cases; ++tc){
        int n_friendships;
        std::cin >> n_friendships;
        std::map<std::string, int> users;
        std::vector<std::pair<int, int>> friendships;
        std::string user1, user2;
        int n_users = 0;
        for(int i = 0; i < n_friendships; ++i){
            std::cin >> user1 >> user2;
            int user1_id, user2_id;
            if(users.find(user1) == users.end()){
                user1_id = n_users;
                users.insert(std::pair<std::string, int> (user1, user1_id));
                n_users++;
            }else{
                user1_id = users.find(user1)->second;
            }
            if(users.find(user2) == users.end()){
                user2_id = n_users;
                users.insert(std::pair<std::string, int> (user2, n_users));
                n_users++;
            }else{
                user2_id = users.find(user2)->second;
            }
            friendships.push_back(std::pair<int, int> (user1_id, user2_id));
        }
        Disjoint_Set relationships = Disjoint_Set(n_users);
        for(int i = 0; i < friendships.size(); ++i){
            std::cout << relationships.subtree_size[relationships.join(friendships[i].first, friendships[i].second)] << std::endl;
        }
    }
}

void irfan_zadaca_001(){
    int n;
    double x, y;
    std::cin >> n;
    Geometry::Polygon poly;
    for(int i = 0; i < n; i++){
        std::cin >> x >> y;
        poly.add_point(Geometry::Point(x, y));
    }

    std::vector<Geometry::Polygon> polygons = Geometry::split_by_intersections(poly);
    for(int i = 0; i < polygons.size(); i++){
        std::cout << "##############" << std::endl << "Polygon " << i << std::endl << "##############" << std::endl;
        polygons[i].log();
    }
    for(int i = 0; i < polygons.size(); i++){
        std::cout << "Area of polygon " << i << ": " << polygons[i].area() << std::endl;
        std::cout << "Perimeter of polygon " << i << ": " << polygons[i].perimeter() << std::endl;
    }

    std::cout << "Enter a point you want to check" << std::endl;
    std::cin >> x >> y;
    Geometry::Point search_for = Geometry::Point(x, y);

    bool found = false;
    for(int i = 0; i < polygons.size(); i++){
        if(polygons[i].is_point_in_polygon(search_for)){
            found = true;
            break;
        }
    }
    if(found)
        std::cout << "Your point is somewhere in the polygon" << std::endl;
    else
        std::cout << "Nah, you missed" << std::endl;
}

void uva_00920(){
    int test_cases;
    std::cin >> test_cases;
    for(int test_case = 0; test_case < test_cases; test_case++){
        int n, x, y;
        std::cin >> n;
        Geometry::Point points[n];

        for(int i = 0; i < n; i++){
            std::cin >> x >> y;
            points[i] = Geometry::Point(x, y);
        }

        std::sort(points, points + n, [](Geometry::Point &a, Geometry::Point &b){
            return a.x < b.x;
        });

        Geometry::Point max_point;
        double sum = 0;
        for(int i = n-2; i >= 0; i--){
            if(points[i].y > max_point.y){
                Geometry::Line slope = Geometry::Line(points[i+1], points[i]);
                Geometry::Point point = Geometry::Point(slope.f_reverse(max_point.y), max_point.y);
                sum += Geometry::dist(point, points[i]);
                max_point = points[i];
            }
        }
        std::cout << std::fixed << std::setprecision(2) <<sum << std::endl;
    }
}

void uva_10263(){
    double x, y;
    while(std::cin >> x){
        int n;
        std::cin >> y;
        std::cin >> n;
        Geometry::Point M = Geometry::Point(x, y);
        Geometry::Point points[n];
        for(int i = 0; i <= n; i++){
            std::cin >> x >> y;
            points[i] = Geometry::Point(x, y);
        }
        double min = DBL_MAX;
        Geometry::Point min_point = Geometry::Point(0,0);
        for(int i = 1; i <= n; i++){
            Geometry::Line_Segment ls;
            ls = Geometry::Line_Segment(points[i-1], points[i]);
            Geometry::Point closest = Geometry::point_to_line_projection(M, ls);
            if(!closest.is_null() && Geometry::is_point_on_line_segment(closest, ls)){
                double dist = Geometry::dist(M, closest);
                if(dist < min){
                    min = dist;
                    min_point = closest;
                }
            }else{
                double dist_a = Geometry::dist(ls.a, M);
                double dist_b = Geometry::dist(ls.b, M);
                if(dist_a < min){
                    min = dist_a;
                    min_point = ls.a;
                }
                if(dist_b < min){
                    min = dist_b;
                    min_point = ls.b;
                }
            }
        }
        std::cout << std::fixed << std::setprecision(4) << min_point.x << std::endl << min_point.y << std::endl;
    }
}

double precise_power(double num, int power){
    double res = num;
    for(int i = 1; i < power; i++)
        res *= num;
    return res;
}



void uva_00902(){
    int n;
    std::string s;
    while(std::cin >> n >> s){
        std::map<std::string, int> map;
        if(s.length() <= n)
            std::cout << s << std::endl;
        else{
            for(int i = 0; i < s.size()-n; i++){
                std::string tmp = "";
                for(int j = 0; j < n; j++){
                    tmp += s[i+j];
                }
                auto ret = map.insert(std::pair<std::string, int>(tmp,1));
                if (ret.second == false)
                    ret.first->second += 1;
            }
            auto max = std::max_element(map.begin(), map.end(), [](std::pair<std::string, int> a,std::pair<std::string, int> b){
                return a.second < b.second;
            });
        std::cout << max->first << std::endl;
        }
    }
}

void uva_10927(){
    int n;
    int cnt = 0;
    while(true){
        cnt++;
        std::cin >> n;
        if(n == 0)
            break;
        int x, y, z;
        std::vector<std::pair<Geometry::Point, int>> poles;
        for(int i = 0; i < n; i++){
            std::cin >> x >> y >> z;
            poles.push_back(std::pair<Geometry::Point, int> (Geometry::Point(x, y), z));
        }
        Geometry::Point T = Geometry::Point(0, 0);
        std::vector<Geometry::Point> hidden;
        bool mem[n];
        std::fill(mem, mem+n, false);
        for(int i = 0; i < n; i++){
            if(!mem[i])
                for(int j = i+1; j < n; j++){
                        if(!mem[j]){
                            double ccw = Geometry::ccw(poles[i].first, poles[j].first, T) ;
                            if(ccw == 0 || ccw == -0){
                                   if(Geometry::dist_nosqrt(poles[i].first, T) < Geometry::dist_nosqrt(poles[j].first, T) && Geometry::quadrant(poles[i].first) == Geometry::quadrant(poles[j].first)){
                                        if(poles[j].second <= poles[i].second){
                                            hidden.push_back(poles[j].first);
                                            mem[j] = true;
                                        }
                                   }else if(!mem[i] && Geometry::quadrant(poles[i].first) == Geometry::quadrant(poles[j].first)){
                                        if(poles[i].second <= poles[j].second){
                                            hidden.push_back(poles[i].first);
                                            mem[i] = true;
                                        }
                                   }
                        }
                    }
                }
        }
        std::sort(hidden.begin(), hidden.end(), [](Geometry::Point &a, Geometry::Point &b){
            if(a.x == b.x)
                return a.y < b.y;
            return a.x < b.x;
        });
        std::cout << "Data set " << cnt << ":" << std::endl;
        if(hidden.size() == 0)
            std::cout << "All the lights are visible." << std::endl;
        else{
            std::cout << "Some lights are not visible:" << std::endl;
            for(int i = 0; i < hidden.size(); i++){
                std::cout << "x = " << (int)hidden[i].x << ", y = " << (int)hidden[i].y << (i == hidden.size()-1 ? "." : ";") << std::endl;
            }
        }
    }
}

void uva_00793(){
    int test_cases;
    std::cin >> test_cases;
    for(int tc = 0; tc < test_cases; tc++){
        int computers;
        std::cin >> computers;
        Disjoint_Set uf = Disjoint_Set(computers+1);
        char query;
        int c1, c2;
        int successful = 0, unsuccessful = 0;
        std::cin.ignore();
      //  int cnt = 0;
        while(1){
            //std::cout << i << std::endl;
        //    std::cin >> query >> c1 >> c2;
            std::string input;
            std::getline(std::cin, input);
            if(input.length() == 0)
                break;
            sscanf(input.c_str(), "%c %d %d\n", &query, &c1, &c2);
            if(query == 'c'){
                uf.join(c1, c2);
           //     cnt++;
             //   if(cnt == 10){
             //     uf.path_compression();
              //    cnt = 0;
              //    }
            }
            else if(uf.same_parent(c1,c2))
                successful++;
            else
                unsuccessful++;
            if(std::cin.eof())
                break;
        }

		std::cout << successful << ',' << unsuccessful << std::endl;
		if(tc != test_cases-1)
			std::cout << std::endl;

    }
}
