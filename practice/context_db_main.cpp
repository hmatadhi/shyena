// C++ program to demonstrate functionality of unordered_map 
#include <iostream> 
#include <unordered_map> 
using namespace std; 
  

class pcap_context {
    int a;
    int b;

    public:    
    pcap_context(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    void set_param_a(int a) 
    {
        this->a = a;
    }

    void set_param_b(int b)
    {
        this->b = b;
    }

    int get_param_a(void) const
    {
        return this->a;
    }

    int get_param_b(void) const
    {
        return this->b;
    }
    
};

bool operator==(pcap_context const &lhs, pcap_context const &rhs) 
{ 
    return ((lhs.get_param_a() == rhs.get_param_a())
        &&  (lhs.get_param_b() == rhs.get_param_b()));
}

struct pcap_hash
{
    std::size_t operator()(pcap_context const& k) const noexcept
    {
      using std::size_t;
      using std::hash;


      int a, b;
      a = k.get_param_a();
      b = k.get_param_b();

      std::size_t h1  = std::hash<int>{}(a);
      std::size_t h2  = std::hash<int>{}(b);

      return (h1 ^ (h2 << 1));
               
    }
};

namespace std
{

    template<> struct hash<pcap_context>
    {
       std::size_t operator()(pcap_context const& k) const noexcept
       {
         using std::size_t;
         using std::hash;


         int a, b;
         a = k.get_param_a();
         b = k.get_param_b();

         std::size_t h1  = std::hash<int>{}(a);
         std::size_t h2  = std::hash<int>{}(b);

         return (h1 ^ (h2 << 1));
                  
       }
    };
}

int check(pcap_context key, unordered_map<pcap_context, double> umap)
{
    if (umap.find(key) == umap.end()) 
        cout << "(" << key.get_param_a() << "," 
                    << key.get_param_b() << ")" << "not found\n\n"; 
    else
        cout << "(" << key.get_param_a() << "," 
                    << key.get_param_b() << ")" << "found\n\n"; 
} 

int main() 
{ 
   pcap_context p1(1, 2);
   pcap_context p2(2, 3);
   pcap_context p3(3, 4);

   unordered_map<pcap_context, double> umap;
   
   umap[p1] = 1.0 ;
   umap[p2] = 2.0 ;
   check(p1, umap);
   check(p2, umap);
   check(p3, umap);
  /* 

    unordered_map<string, double>:: iterator itr; 
    cout << "\nAll Elements : \n"; 
    for (itr = umap.begin(); itr != umap.end(); itr++) 
    { 
        // itr works as a pointer to pair<string, double> 
        // type itr->first stores the key part  and 
        // itr->second stroes the value part 
        cout << itr->first << "  " << itr->second << endl; 
     }
   */  
} 
