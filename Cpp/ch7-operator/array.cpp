#include <iostream>
using namespace std;
/**
 * 下标运算符[]，通常有两种重载版本：const成员函数和非const成员函数
 * 因为一个const对象a，a[i]只能调用cosnt成员函数版本。见下面的
 * const int& operator[](int i) const 
 * 此外，函数（包括成员函数和运算符函数），返回一个引用，
 * 意味着该函数可以放在等号=的左边，当然也可以放在等号=的右边。
 * */

class Array {
private:
    int len;
    int* data;
public:
    Array(int len):len(len),data(new int[len]){  }
	~Array(){  delete[] data; }

	Array(const Array& a):len(a.len),data(new int[a.len]){
		std::copy(a.data, a.data+len, data);
	}

	Array& operator=(const Array& a){
		if(this != &a){
			delete[] data;
			len = a.len;
			data = new int[len];
			std::copy(a.data, a.data+len, data);
		}
		return *this;
    }

    Array(Array&&a) noexcept:len(a.len),data(a.data){
		a.data = nullptr;
		a.len =0;
	}

	Array& operator=(Array&& a) noexcept{
		if(this != &a){
			delete[] data;
			len = a.len;
			data = a.data;
			a.data = nullptr;
			a.len =0;
		}
		return *this;
	}

    int& operator[](int i){ //cout<<"here"<<endl;
        return data[i];
    }

    const int& operator[](int i) const{ //cout<<"const"<<endl;
        return data[i];
    }

    friend ostream& operator<<(ostream& os, const Array& a){
        for (size_t i = 0; i < a.len; i++)
            os<<a[i]<<" ";  //a[i]调用const int& operator[](int i) const
        return os;
    }

    friend istream& operator>>(istream& is, Array& a){
        for (size_t i = 0; i < a.len; i++)
            is>>a[i];       //a[i]调用int& operator[](int i)
        return is;
    }

};

int main(){
    Array a(10);
    cin>>a;
    cout<<a<<endl;
    a[4] = 30;  //a[i]调用int& operator[](int i) 放在=的左边
    cout<<a[4]; //a[i]调用const int& operator[](int i) const放在运算符<<的右边
    return 0;
}