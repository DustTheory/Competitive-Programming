#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

class BigInteger{
    private:
	string number;

	public:
	BigInteger(){
	}
	BigInteger(string _number){
		number = _number;
		remove_leading_zeros();
		if(number == "" || number == "-")
            number = "0";
	}

	bool is_positive () const{
        return number[0] != '-';
	}

	BigInteger abs() const{
        BigInteger res = *this;
        if(!res.is_positive())
            res.number.erase(0,1);
        return res;
	}

	string as_string(){
        return number;
	}

	void remove_leading_zeros(){
        int i = 0+!is_positive();
        while(number[i] == '0')
            i++;
        number.erase(0+!is_positive(), i);
    }

	string flip(){
        reverse(number.begin(), number.end());
        remove_leading_zeros();
        return number;
	}

	short mod2(){
        if(is_zero())
            return 0;
        short last_digit = number[number.length()-1]-'0';
        return (10+last_digit)%2;
	}

	bool is_zero() const{
        return number == "0";
	}

	bool is_one() const{
        return number == "1";
	}

	int length() const{
        return number.length() - !is_positive();
	}

	void operator=(const string &num){
        number = num;
	}

	void operator=(const int &num){
        number = to_string(num);
	}

	void operator++(int num){
        (*this) = (*this) + BigInteger("1");
	}

	void operator+=(const BigInteger &num){
        (*this) = (*this) + num;
	}

	bool operator==(const BigInteger &num){
        return number == num.number;
	}

	bool operator!=(const BigInteger &num){
        return number != num.number;
	}

	bool operator<(const BigInteger& num){
        if(!is_positive() && num.is_positive())
            return true;
        if(is_positive() && !num.is_positive())
            return false;
        if(!is_positive() && !num.is_positive())
            return !((*this).abs() < num.abs());
        int l1 = length(), l2 = num.length();
        if(l1 < l2)
            return true;
        else if(l1 > l2)
            return false;
        for(int i = 0; i < number.length(); i++){
            if(number[i] != num.number[i])
                return number[i] < num.number[i];
        }
        return false;
	}

	bool operator>(const BigInteger& num){
        return (*this) != num && !((*this) < num);
	}

	bool operator>=(const BigInteger& num){
        return !((*this) < num);
	}

	bool operator<=(const BigInteger &num){
        return (*this) == num || (*this) < num;
	}

	BigInteger operator-(){
        if(number == "0")
            return *this;
        if(is_positive()){
            number = '-' + number;
            return *this;
        }
        return abs();
	}

	BigInteger operator+(const BigInteger& num){
        if(is_positive() == num.is_positive()){
            string result = "";
            int i = number.length() - 1, j = num.number.length() - 1;
            int a, b;
            int carry = 0;
            while(true){
                if(i < !is_positive() && j < !num.is_positive())
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
            if(!is_positive() && !num.is_positive())
                result += '-';
            reverse(result.begin(), result.end());
            return BigInteger(result);
		}else if(is_positive() && !num.is_positive()){
            return *this - num.abs();
        }else if(!is_positive() && num.is_positive()){
            return (*this).abs() - num;
        }
	}

	char mod10(){
        return number[number.length()-1];
	}
	BigInteger divide10(){
        return BigInteger(number.substr(0, number.length()-1));
	}

	BigInteger operator-(const BigInteger &num){
        if(!is_positive() && !num.is_positive())
            return (num.abs()) - (-(*this));
        if(is_positive() && !num.is_positive()){
            return (*this) + num.abs();
        }
        if(!is_positive() && num.is_positive()){
            return -(-(*this) + num);
        }
        const BigInteger *maxi, *mini;
        bool negative = false;
        if((*this) > num){
            maxi = this;
            mini = &num;
        }else{
            negative = true;
            maxi = &num;
            mini = this;
        }
        string result = "";
        int i = maxi->number.length() - 1, j = mini->number.length() - 1;
        int a, b;
        int borrow = 0;
        while(true){
            if(i < !maxi->is_positive() && j < !mini->is_positive())
                break;
            if(i < 0)
                a = 0;
            else
                a = maxi->number[i] - '0';
            if(j < 0)
                b = 0;
            else
                b = mini->number[j] - '0';
            int sum;
            if(a >= b + borrow){
                sum = a - (b + borrow);
                borrow = 0;
            }else{
                sum = 10+a -(b+borrow);
                borrow = 1;
            }
            if(!(i <= 0 && j <= 0 && sum == 0))
                result += '0' + sum;
            i--;
            j--;
        }
        reverse(result.begin(), result.end());
        return negative ? -BigInteger(result) : BigInteger(result);
	}

	BigInteger operator*(const int &num) const{
        if(num == 0)
            return BigInteger("0");
        if(num == 1)
            return *this;
        string result = "";
        int n = num;
        if(n < 0)
            n *= -1;
        int i = number.length() - 1;
        int a;
        int carry = 0;
        while(true){
            if(i < !is_positive())
                break;
            a = number[i] - '0';
            int sum = a*n + carry;
            result += '0' + sum%10;
            carry = sum/10;
            i--;
        }
        while(carry > 0){
            result += '0' + carry%10;
            carry/=10;
        }
        reverse(result.begin(), result.end());
        if((num>=0) != is_positive())
            return -BigInteger(result);
        else
            return BigInteger(result);
    }

    BigInteger operator*(const BigInteger& num){
        if(num.is_zero())
            return BigInteger("0");
        if(num.is_one())
            return *this;
        string result = "";
        BigInteger n = num.abs();
        int i = number.length() - 1;
        int a;
        BigInteger carry = BigInteger("0");
        while(true){
            if(i < !is_positive())
                break;
            a = number[i] - '0';
            BigInteger sum = n*a + carry;
            result += sum.mod10();
            carry = sum.divide10();
            i--;
        }
        reverse(carry.number.begin(), carry.number.end());
        result += carry.number;
        reverse(result.begin(), result.end());
        if(num.is_positive() != is_positive())
            return -BigInteger(result);
        else
            return BigInteger(result);
    }

    BigInteger pow(const BigInteger &num){
        BigInteger one = BigInteger("1");
        BigInteger result = one;
        for(BigInteger i = BigInteger("0"); i < num; i = i + one){
            result = result * (*this);
        }
        return result;
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

BigInteger last_n_digits(BigInteger &num, int n){
    string tmp = num.as_string();
    if(tmp.length() > n)
        tmp = tmp.substr(tmp.length()-n, n);
    return BigInteger(tmp);
}

BigInteger last_n_digits2(BigInteger num, int n){
    string tmp = num.as_string();
    if(tmp.length() > n)
        tmp = tmp.substr(tmp.length()-n, n);
    return BigInteger(tmp);
}



BigInteger generate_fibonacci(int a, int b, int n, int m){
    BigInteger fibonacci1, fibonacci2, tmp;
    fibonacci1 = a;
    fibonacci2 = b;
    fibonacci1 = last_n_digits(fibonacci1, m);
    fibonacci2 = last_n_digits(fibonacci2, m);
    for(int i = 2; i <= n; i++){
        tmp = fibonacci2;
        fibonacci2 = last_n_digits2(last_n_digits(fibonacci1, m) + last_n_digits(fibonacci2, m), m);
        fibonacci1 = tmp;
        //if(n % 10000 == 0)
          //  cout << i << " " << fibonacci2 << endl;
    }
    return fibonacci2;
}

int main(){

    int a, b, n, m;
    while(cin >> a >> b >> n >> m)
        cout << generate_fibonacci(a, b, n, m) << endl;
}
