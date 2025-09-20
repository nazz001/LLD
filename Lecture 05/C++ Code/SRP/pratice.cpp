#include<iostream>
#include<vector>
using namespace std;
// Product class representing any item in eCommerce.
class Product {
    public:
    string name;
    double price;
    Product(string name,double price)
    {
        this->name=name;
        this->price=price;
    }

};
// ShoppingCart: Responsible for Cart related business logic.
class ShoppingCart {
    private:
    vector<Product*> products; // Store heap-allocated products
    public:
    void addProduct(Product* p)
    { products.push_back(p); }

    const vector<Product*>& getProducts() { return products; }
    //Calculates total price in cart.
    double calculateTotal()
    {
        double total=0;
        for(auto p:products)
        {
            total+=p->price;
        }
        return total;
    }
};
// ShoppingCartPrinter: Responsible for printing invoices
class ShoppingCartPrinter {
    private:
    ShoppingCart* cart;
    public:
    ShoppingCartPrinter(ShoppingCart* cart)
    { this->cart=cart; }
    void printInvoice()
    {
        cout<<"Shopping Cart Invoice:\n";
        for(auto p:cart->getProducts())
        {
            cout<<p->name<<" - Rs "<<p->price<<endl;
        }
        cout<<"Total: Rs "<<cart->calculateTotal()<<endl;
    }
};
class shoppingCartStorage
{
    private:
    ShoppingCart* cart;
    public:
    shoppingCartStorage(ShoppingCart* cart)
    { this->cart=cart; }
    void saveToDatabase()
    {
        cout<<"Saving cart with total Rs "<<cart->calculateTotal()<<" to database."<<endl;
    }

};  
int main()
{
    ShoppingCart cart;
    cart.addProduct(new Product("Laptop",50000));
    cart.addProduct(new Product("Mouse",1500));
    cart.addProduct(new Product("Keyboard",3000));

    ShoppingCartPrinter printer(&cart);
    printer.printInvoice();

    shoppingCartStorage storage(&cart);
    storage.saveToDatabase();

    return 0;
}



