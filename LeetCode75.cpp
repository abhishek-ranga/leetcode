#include<iostream>
#include<vector>
using namespace std;
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

// NIGGA APPROACH-
// void sort(vector<int> &v){
//     int n0s=0;
//     int n1s=0;
//     int i;
//     for(i=0; i<v.size(); i++){
//         if(v[i]==0) n0s++;
//         if(v[i]==1) n1s++;
//     }
//     int a=0;
//     i=0;
//     while(a<n0s){
//         v[i]=0;
//         a++;
//         i++;
//     }
//     a=0;
//     while(a<n1s){
//         v[i]=1;
//         a++;
//         i++;
//     }
//     a=0;
//     while(a<v.size()){
//         v[i]=2;
//         a++;
//         i++;
//     }
//     return;
// }

// METHOD-1 {2 PASS} 
// void sortColors(vector<int>& v) {
//     int n0s=0;
//     int n1s=0;
//     int n2s=0;
//     for(int i=0; i<v.size(); i++){
//         if(v[i]==0) n0s++;
//         if(v[i]==1) n1s++;
//         if(v[i]==2) n2s++;
//     }
//     for(int i=0; i<v.size(); i++){
//         if(i<n0s) v[i]=0;
//         else if(i<n0s+n1s) v[i]=1;
//         else v[i]=2;
//     }
//     return;
// }

// METHOD-2 {3 POINTER}
// MID KE BAARE MEIN SOCHO.
// INDEX 0 SE LEKAR LOW-1 / YAANI KI LOW SE NEECHE WALE MEIN HUME 0 BHARNE HAI.
// INDEX HIGH+1 SE LEKAR END TAK / YAANI KI HIGH SE AAGE WALE MEIN HUME 2 BHARNA HAI.
// INDEX LOW SE LEKAR MID-1 TAK HUMARA 1 HONA CHAHIYE, YEH HUMARA APNE AAP BAN JAYEGA JAB END MEIN MID>HIGH HOGA AND LOOP BREAK HOGA TOH HIGH TAK / YA MID SE NEECHE TAK HUMARA 1 BAN JAYEGA.
// END MEIN HUMARE LOW PAR AUR HIGH PAR 1 AAYEGA AUR INKE BEECH MEIN BHI PURA 1 HOGA.
void dutchflagalgorithm(vector<int> &v){
    int n = v.size();
    int low = 0;
    int mid = 0;
    int high = n-1;
    while(mid<=high){
        if(v[mid]==2){
            swap(&v[mid],&v[high]);
            high--;
        }
        if(v[mid]==0){
            swap(&v[mid],&v[low]);
            low++;
            mid++;
        }
        if(v[mid]==1){
            mid++;
        }
    }
    return;
}

int main(){
    int size;
    cout<<"enter size; ";
    cin>>size;
    vector<int> v;
    cout<<"enter array: ";
    for(int i=0; i<size; i++){
        int q;
        cin>>q;
        v.push_back(q);
    }

    // NIGGA APPROACH-
    // sort(v);

    // 2PASS-
    // sortColors(v);

    // 3POINTER-
    dutchflagalgorithm(v);

    cout<<"sorted array: ";
    for(int i=0; i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}