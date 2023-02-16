#include <iostream>
#include <string>

using namespace std;

class Good {
    private:
        string name;
        double price;
        int code;
    
    public:
        Good(): name("Good"), price(0), code(1) {}
        Good(string n, double p, int c): name(n), price(p), code(c) {}
        Good(const Good &good): name(good.name), price(good.price), code(good.code) {}
        
        friend istream& operator>>(istream& is, Good& good) {
    		cout << "Enter name:" << endl;
    		is >> good.name;
    		cout << "Enter price:" << endl;
    		is >> good.price;
    		cout << "Enter code:" << endl;
    		is >> good.code;
    
    		return is;
    	}
    	
    	friend ostream& operator<<(ostream& os, Good& good) {
    		os << good.name << " " << good.price << " #" << good.code << endl;
    
    		return os;
    	}
    	
    	string getName() {
    	    return name;
    	}
    	double getPrice() {
    	    return price;
    	}
};

class Cart {
    private:
    Good* goods;
    int* count;
    int cur;
    
    public:
    Cart(): cur(0) {
        goods = new Good[1000];
        count = new int[1000];
    }
    
    double calcPrice() {
        double res = 0;
        
        for (int i = 0; i < 1000; i++) {
            res += goods[i].getPrice() * count[i];
        }
        return res;
    }
    
    void addGood(Good good, int n) {
        count[cur] = n;
        goods[cur] = good;
        cur++;
    }
    
    void removeGood(Good good, int n) {
        int i;
        
        for (i = 0; i < 1000; i++) {
            if (goods[i].getName() == good.getName()) {
                count[i] -= n;
                break;
            }
        }
        if (count[i] == 0) {
            for (int j = i; j < 1000; j++) {
                if (count[j] != 0 && count[j + 1] != 0) {
                    count[j] = count[j + 1];
                    goods[j] = goods[j + 1];
                }
                else {
                    cur = j;
                    break;
                }
            }
        }
        
    }
    int* getCount(){
            return count;
        }
        
        Good* getGoods(){
            return goods;
        }
    
    int Count() {
        int c = 0;
        for (int i = 0; i < 1000; i++) {
            c += count[i];
        }
        return c;
    }
    
    friend ostream& operator<<(ostream& os, Cart& cart) {
		os << "There are " << cart.Count() << " Total price is " << cart.calcPrice() << "$" << endl;
		os << "List:" << endl;
		for (int i = 0; i < 1000; i++) {
		    if (cart.getCount()[i] != 0) {
		        os << cart.getGoods()[i].getName() << " - " << cart.getCount()[i] << endl;
		    }
		}
		
		return os;
	}
    
};

int main()
{
    Good g1;
    Good g2;
    Good g3;
    
    Cart cart;
    cin >> g1;
    cin >> g2;
    cin >> g3;
    
    cart.addGood(g1, 3);
    cart.addGood(g2, 1);
    cart.addGood(g3, 11);
    
    cout << cart;
    
    cart.removeGood(g1,2);
    cart.removeGood(g2,1);
    
    cout << cart;

    return 0;
}