
void TEST007(){
    std::vector<Geometry::Point> vec = {
        Geometry::Point(1, 1),
        Geometry::Point(3, 3),
        Geometry::Point(9, 1),
        Geometry::Point(12, 3),
        Geometry::Point(9, 7),
        Geometry::Point(1, 7)
    };
    Geometry::Polygon p = Geometry::Polygon(vec);
    p.log();
    std::cout << p.is_point_in_polygon(Geometry::Point(2, 3)) << std::endl;
    std::cout << p.area() << std::endl;
}

void TEST_KMP(){
    std::string to_read = "I DO NOT LIKE SEVENTY SEV BUT SEVENTY SEVENTY SEVEN SEVSEVENTY SEVEN";
    std::string to_find = "SEVENTY SEVEN";
    std::cout << "Next line should say 30:" << std::endl;
    std::cout << StringProcessing::kmp_find_first(to_read, to_find) << std::endl;
    std::cout << "Next line should say 30, 38, 55:" << std::endl;
    std::vector<int> found = StringProcessing::kmp_find_multiple(to_read, to_find);
    for(int i = 0; i < found.size(); i++)
        std::cout << found[i] << " , ";// (i == found.size()-1) ? " " : ", ";
    std::cout << std::endl;
}

void TEST_CONVEX_HULL(){

    std::vector<Geometry::Point> vec = {
        Geometry::Point(1, 1),
        Geometry::Point(3, 1),
        Geometry::Point(2, 2),
        Geometry::Point(3, 3),
        Geometry::Point(1, 3)
    };

    std::vector<Geometry::Point> test = Geometry::convex_hull(vec);
    for(int i = 0; i < test.size(); i++)
        test[i].log();
}

void TEST_VECTOR_PROJECTION(){
    Geometry::Vector2 vec1 = Geometry::Vector2(1,1);
    Geometry::Vector2 vec2 = Geometry::Vector2(2,0);
    Geometry::vector_projection(vec1, vec2).log();
    Geometry::vector_projection(vec2, vec1).log();
}

void TEST_DIST_TO_LINE_SEGMENT(){
    Geometry::Line_Segment ls = Geometry::Line_Segment(Geometry::Point(5, 5), Geometry::Point(9,-5));
    Geometry::Point M = Geometry::Point(6, -3);
    std::cout << dist_to_line_segment(M, ls) << std::endl;
}

void TEST_TRIE(){
    std::string a = "ishak";
    std::string b = "ishrana";
    std::string c = "pohrana";
    StringProcessing::Suffix_Tree trie;
    trie.add_word(a);
    trie.add_word(b);
    trie.add_word(c);
    trie.log();
}

void TEST_BST(){
    Graph::Binary_Search_Tree bst;
    bst.add_number(2);
    bst.add_number(1);
    bst.add_number(3);
    bst.log();
}

double precise_power(double num, int power){
    double res = num;
    for(int i = 1; i < power; i++)
        res *= num;
    return res;
}

void irfan_klub_001(){
  /*  int n;
    std::cin >> n;
    double last = log(102./101.);
    double test = log(102.0) - log(101.0);
    std::cout << std::fixed << std::setprecision(20 ) << test << " " << last << std::endl;
    for(int i = 1; i <= n; i++){
        last = ((double)(1 << i) - 1.0)/((double)i) - (100.0*last) ;
    }
    std::cout << last << std::endl;
    */
    double sum = 0;
    int n = 10;
    for(int  i = 0; i < 5; i++){
        sum += (1.0 - (double)(1 << (n+1+i)))/(precise_power(-100.0, i+1)*(n+1.0+i));
    }
    std::cout << sum << std::endl;
}

void TEST_DISJOINT_SET(){
    Disjoint_Set uf = Disjoint_Set(10);
    uf.join(1, 2);
    uf.join(3, 2);
    uf.join(4, 5);
    uf.join(1, 4);
    uf.log();
    std::cout << "KEK" << std::endl;
    uf.path_compression();
    uf.log();
}

