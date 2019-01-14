nclude <iostream>

using namespace std;

void _flood_fill(int** mc, int i, int j, int r, int c, bool binary, int color){
	    if(i <= 0 || j <= 0 || i > r || j > c)
		            return;
	        if(mc[i][j] != binary)
			        return;
		    mc[i][j] = color;
		        _flood_fill(mc, i+1, j, r, c, binary, color);
			    _flood_fill(mc, i-1, j, r, c, binary, color);
			        _flood_fill(mc, i, j+1, r, c, binary, color);
				    _flood_fill(mc, i, j-1, r, c, binary, color);
}

void flood_fill(int** mc, int r, int c){
	    int color = 2;
	        for(int i = 1; i <= r; i++){
			        for(int j = 1; j <= c; j++){
					            if(mc[i][j] <= 1){
							                    _flood_fill(mc, i, j, r, c, mc[i][j] != 0,  color);
									                    color++;
											                }
						            }
				    }
}

int main(){
	    int r, c;
	        cin >> r >> c;
		    char m[r+1][c+1];
		        for(int i = 1; i <= r; i++)
				        for(int j = 1; j <= c; j++)
						            cin >> m[i][j];
			    int** mc = new int*[r+1];
			        for(int i = 0; i <= r; i++)
					        mc[i] = new int[c+1];

				    for(int i = 0; i <= r; i++){
					            for(int j = 0; j <= c; j++){
							                mc[i][j] = m[i][j]-'0';

									        }
						        }
				        flood_fill(mc, r, c);
					    int q;
					        cin >> q;
						    for(int i = 0; i < q; i++){
							            int fromi, fromj, toi, toj;
								            cin >> fromi >> fromj >> toi >> toj;
									            if(mc[fromi][fromj] == mc[toi][toj])
											                cout << (m[fromi][fromj] == '0' ? "binary" : "decimal") << endl;
										            else
												                cout << "neither" << endl;
											        }

}


