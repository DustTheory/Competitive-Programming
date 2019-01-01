#include <iostream>
#include <algorithm>

using namespace std;

class BigInteger{
    private:
	string number;
    bool positive;

	public:
	BigInteger(){
        positive = true;
	}
	BigInteger(string _number){
		number = _number;
		positive = true;
	}

	string as_string(){
        return number;
	}

	string flip(){
        reverse(number.begin(), number.end());
        int i = 0;
        while(number[i] == '0')
            i++;
        //cout << number << " " << number.length()-i << " " << i << endl;
        number.erase(0, i);
        return number;
	}

	BigInteger operator+(const BigInteger& num){
        if(!positive || !num.positive)
            return BigInteger("NaN");
		string result = "";
		int i = number.length()-1, j = num.number.length()-1;
		int a, b;
		int carry = 0;
		while(true){
			if(i < 0 && j < 0)
				break;
			if(i < 0)
				a = 0;
			else
				a = number[i] - '0';
			if(j < 0)
				b = 0;
			else
				b = num.number[j] - '0';
			int sum = a + b + carry;
			result += '0' + sum%10;
			carry = sum/10;
            i--;
            j--;
		}
		while(carry > 0){
			result += '0' + carry%10;
			carry/=10;
		}
        reverse(result.begin(), result.end());
		return BigInteger(result);
	}

    friend ostream& operator<< (ostream& stream, const BigInteger& num){
        stream << num.number;
        return stream;
    }
    friend istream& operator>> (istream& stream, BigInteger &num){
        stream >> num.number;
        return stream;
    }
};

int main(){
    int n;
    cin >> n;
        for(int i = 0; i < n; i++){
        BigInteger a, b;
        cin >> a >> b;
        a.flip(); b.flip();
        cout << (a + b).flip() << endl;
	}
}
