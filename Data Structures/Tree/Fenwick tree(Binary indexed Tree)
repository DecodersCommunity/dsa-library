//**********************************************************************Fenwick Tree/Binary Indexed Tree********************************************************
template<class T>
class fenwick_tree
{ 
 private:
 vector<T> tre;
 public:
 fenwick_tree(T n)
 {
   tre.resize(n+1);
 }
 void add(T index,T value)
 {
    for(;index<=tre.size()-1;index+=(index&(-index)))
    tre[index]+=value;
 }
 T sum_i(T index)
 {
     T ans=0;
     for(;index>0;index-=(index&(-index)))
     ans+=tre[index];
     return ans;
 } 
}; 
