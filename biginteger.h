#include <iostream>
#include <algorithm>

using namespace std;

class BigInteger{
    private:
	string number;

	public:
	BigInteger(){
	}
	BigInteger(string _number){
		number = _number;
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
        int i = 0;
        while(number[i] == '0')
            i++;
        number.erase(0, i);
    }

	string flip(){
        reverse(number.begin(), number.end());
        remove_leading_zeros();
        return number;
	}

	int length() const{
        return number.length() - !is_positive();
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
            remove_leading_zeros();
            return BigInteger(result);
		}else if(is_positive() && !num.is_positive()){
            return *this - num.abs();
        }else if(!is_positive() && num.is_positive()){
            return (*this).abs() - num;
        }
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
            result += '0' + sum;
            i--;
            j--;
        }
        reverse(result.begin(), result.end());
        BigInteger res = BigInteger(result);
        res.remove_leading_zeros();
        if(negative)
            res = -res;
        return res;
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

