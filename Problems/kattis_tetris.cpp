#include <iostream>

using namespace std;

int main(){
	int c, p;
	cin >> c >> p;
	int heights[c];
	for(int i = 0; i < c; i++)
		cin >> heights[i];
	int cnt = 0;
	for(int i = 0; i < c; i++){
		if(p == 1){
			// Shape:
			// #
			// #
			// #
			// #
			// or
			// #####
			//
			// First position can always be placed
			cnt++;
			// Second position can sometimes
			if(i+3 < c)
				if(heights[i] == heights[i+1] && heights[i+1] == heights[i+2] && heights[i+2] == heights[i+3])
					cnt++;
		}else if(p == 2){
			// Shape:
			// ##
			// ##
			// Only one way to put it
			if(i+1 < c && heights[i] == heights[i+1])
				cnt++;
		}else if(p == 3){
			// Shape:
			//  ##
			// ##
			// or
			// #
			// ##
			//  #
			// 
			// First position test:
			if(i+2 < c && heights[i] == heights[i+1] && heights[i+1] == heights[i+2]-1)
				cnt++;
			// Second position test:
			if(i+1 < c && heights[i]-1 == heights[i+1])
				cnt++;
		}else if(p == 4){
			// Shape:
			//  #
			// ##
			// #
			// or
			// ##
			//  ##
			//
			// First position
			if(i+1 < c && heights[i] == heights[i+1]-1)
				cnt++;
			// Second position
			if(i+2 < c && (heights[i]-1) == heights[i+1]  && heights[i+1] == heights[i+2]){
				cnt++;
			}
		}else if(p == 5){
			// Shape:
			//  #
			// ###
			// or
			// #
			// ##
			// #
			// or
			// ###
			//  #
			// or
			//  #
			// ##
			//  #
			//
			// First position:
			if(i+2 < c && heights[i] == heights[i+1] && heights[i+1] == heights[i+2])
				cnt++;
			// Secod position:
			if(i+1 < c && heights[i] == heights[i+1]-1)
				cnt++;
			// Third position
			if(i+2 < c && heights[i]-1 == heights[i+1] && heights[i+1] == heights[i+2]-1)
				cnt++;
			// Fourth position
			if(i+1 < c && heights[i]-1 == heights[i+1])
				cnt++;
		}else if(p == 6){
			// Shape:
			//   #
			// ###
			// or
			// #
			// #
			// ##
			// or
			// ###
			// #
			// or
			// ##	
			//  #
			//  #
			//
			// First position:
			if(i+2 < c && heights[i] == heights[i+1] && heights[i+1] == heights[i+2])
				cnt++;
			// Second position:
			if(i+1 < c && heights[i] == heights[i+1])
				cnt++;
			// Third position
			if(i+2 < c && heights[i] == heights[i+1]-1 && heights[i] == heights[i+2]-1)
				cnt++;
			// Fourth position
			if(i+1 < c && heights[i+1]+2 == heights[i])
				cnt++;
		}else if(p == 7){
			// Shape:
			// #
			// ###
			// or
			// ##
			// #
			// #
			// or
			// ###
			//   #
			// or
			//  #
			//  #
			// ##
			//
			// First position:
			if(i+2 < c && heights[i] == heights[i+1] && heights[i+1] == heights[i+2])
				cnt++;
			// Second position:
			if(i+1 < c && heights[i]+2 == heights[i+1])
				cnt++;
			// Third position:
			if(i+2 < c && heights[i]-1 == heights[i+1]-1 && heights[i+1]-1 == heights[i+2])
				cnt++;
			// Fourth position:
			if(i+1 < c && heights[i] == heights[i+1])
				cnt++;
		}
	}
	cout << cnt << endl;
}
