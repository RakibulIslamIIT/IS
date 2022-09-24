#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long int ll;

ll A = 0x6a09e667f3bcc908;
ll B = 0xbb67ae8584caa73b;
ll C = 0x3c6ef372fe94f82b;
ll D = 0xa54ff53a5f1d36f1;
ll E = 0x510e527fade682d1;
ll F = 0x9b05688c2b3e6c1f;
ll G = 0x1f83d9abfb41bd6b;
ll H = 0x5be0cd19137e2179;

const ll ROUND_CONSTANT[80] =
      { 0x428a2f98d728ae22, 0x7137449123ef65cd, 0xb5c0fbcfec4d3b2f, 0xe9b5dba58189dbbc,
        0x3956c25bf348b538, 0x59f111f1b605d019, 0x923f82a4af194f9b, 0xab1c5ed5da6d8118,
        0xd807aa98a3030242, 0x12835b0145706fbe, 0x243185be4ee4b28c, 0x550c7dc3d5ffb4e2,
        0x72be5d74f27b896f, 0x80deb1fe3b1696b1, 0x9bdc06a725c71235, 0xc19bf174cf692694,
        0xe49b69c19ef14ad2, 0xefbe4786384f25e3, 0x0fc19dc68b8cd5b5, 0x240ca1cc77ac9c65,
        0x2de92c6f592b0275, 0x4a7484aa6ea6e483, 0x5cb0a9dcbd41fbd4, 0x76f988da831153b5,
        0x983e5152ee66dfab, 0xa831c66d2db43210, 0xb00327c898fb213f, 0xbf597fc7beef0ee4,
        0xc6e00bf33da88fc2, 0xd5a79147930aa725, 0x06ca6351e003826f, 0x142929670a0e6e70,
        0x27b70a8546d22ffc, 0x2e1b21385c26c926, 0x4d2c6dfc5ac42aed, 0x53380d139d95b3df,
        0x650a73548baf63de, 0x766a0abb3c77b2a8, 0x81c2c92e47edaee6, 0x92722c851482353b,
        0xa2bfe8a14cf10364, 0xa81a664bbc423001, 0xc24b8b70d0f89791, 0xc76c51a30654be30,
        0xd192e819d6ef5218, 0xd69906245565a910, 0xf40e35855771202a, 0x106aa07032bbd1b8,
        0x19a4c116b8d2d0c8, 0x1e376c085141ab53, 0x2748774cdf8eeb99, 0x34b0bcb5e19b48a8,
        0x391c0cb3c5c95a63, 0x4ed8aa4ae3418acb, 0x5b9cca4f7763e373, 0x682e6ff3d6b2b8a3,
        0x748f82ee5defb2fc, 0x78a5636f43172f60, 0x84c87814a1f0ab72, 0x8cc702081a6439ec,
        0x90befffa23631e28, 0xa4506cebde82bde9, 0xbef9a3f7b2c67915, 0xc67178f2e372532b,
        0xca273eceea26619c, 0xd186b8c721c0c207, 0xeada7dd6cde0eb1e, 0xf57d4f7fee6ed178,
        0x06f067aa72176fba, 0x0a637dc5a2c898a6, 0x113f9804bef90dae, 0x1b710b35131c471b,
        0x28db77f523047d84, 0x32caab7b40c72493, 0x3c9ebe0a15c9bebc, 0x431d67c49c100d4c,
        0x4cc5d4becb3e42b6, 0x597f299cfc657e2a, 0x5fcb6fab3ad6faec, 0x6c44198c4a475817 };

string binary_to_hex(string bin)
{
    if (bin == "0000") return "0";
    else if (bin == "0001") return "1";
    else if (bin == "0010") return "2";
    else if (bin == "0011") return "3";
    else if (bin == "0100") return "4";
    else if (bin == "0101") return "5";
    else if (bin == "0110") return "6";
    else if (bin == "0111") return "7";
    else if (bin == "1000") return "8";
    else if (bin == "1001") return "9";
    else if (bin == "1010") return "A";
    else if (bin == "1011") return "B";
    else if (bin == "1100") return "C";
    else if (bin == "1101") return "D";
    else if (bin == "1110") return "E";
    else if (bin == "1111") return "F";
}

string dec_to_hex(ll dec)
{
    string bin= bitset<64>(dec).to_string();

    string hex, tmp;

    for(int i=0; i<bin.length(); i+=4){
        tmp= bin.substr(i, 4);
        hex+=binary_to_hex(tmp);
    }

    return hex;
}


ll MSG[1024]={};

ll rotate_right(ll val, ll pos)
{
    return ( (val >> pos) | (val << 64-pos) );
}

ll shift_right(ll val, ll pos)
{
    return (val >> pos);
}

ll blliodec(string bin)
{
    return bitset<64>(bin).to_ullong();
}

void didvide_into_chunks(string block)
{
    ll chunk_num=0;

    for(ll i=0; i<block.length(); i+=64, chunk_num++) MSG[chunk_num]= blliodec(block.substr(i, 64));

    for(ll i=16; i<80; i++){

        ll wordA= rotate_right(MSG[i-2], 19) ^ rotate_right(MSG[i-2], 61) ^ shift_right(MSG[i-2], 6);
        ll wordB= MSG[i-7];
        ll wordC=  rotate_right(MSG[i-15], 1) ^ rotate_right(MSG[i-15], 8) ^ shift_right(MSG[i-15], 7);
        ll wordD= MSG[i-16];


        MSG[i]= wordA+ wordB+ wordC+ wordD;
    }
}

ll ch_val(ll a, ll b, ll c)
{
    return ( (a & b) ^ (~a & c));
}

ll sigmaE(ll a)
{
    return ( rotate_right(a, 14) ^ rotate_right(a, 18) ^ rotate_right(a, 41) );
}

ll sigmaA(ll a)
{
    return ( rotate_right(a, 28) ^ rotate_right(a, 34) ^ rotate_right(a, 39) );
}

ll major(ll a, ll b, ll c)
{
    return ( (a & b) ^ (b & c) ^ (c & a) );
}

void f(ll a, ll b, ll c, ll& d, ll e, ll f, ll g, ll& h, ll cont)
{
    ll t1= h+ ch_val(e, f, g)+ sigmaE(e)+ MSG[cont]+ ROUND_CONSTANT[cont];
    ll t2= sigmaA(a)+ major(a, b, c);

    d+= t1;
    h= t1+ t2;
}

string SHA_512(string str)
{
    stringstream string_stream;

    for(ll i=0; i<str.length(); i++){
        string_stream<< bitset<8>(str[i]);
    }

    string input;

    input= string_stream.str();

    ll length= input.length();
    ll mod= length%1024;
    ll to_add;

    if(1024- mod>=128) to_add= 1024-mod;
    else to_add= 2048- mod;

    input+="1";

    for(ll i=0; i<to_add-129; i++) input+="0";

    string len_bits= bitset<128>(length).to_string();

    input+=len_bits;


    ll tot_blocks= input.length()/1024;
    ll chunk_num= 0;
    string blocks[tot_blocks+1];

    for(ll i=0; i<input.length(); i+=1024, chunk_num++) blocks[chunk_num]= input.substr(i, 1024);



    ll AA, BB, CC, DD, EE, FF, GG, HH;

    for(ll i=0; i<tot_blocks; i++){

        didvide_into_chunks(blocks[i]);

        AA = A;
        BB = B;
        CC = C;
        DD = D;
        EE = E;
        FF = F;
        GG = G;
        HH = H;

        ll cnt=0;

        for(ll j=0; j<10; j++){
            f(A, B, C, D, E, F, G, H, cnt);
            cnt++;
            f(H, A, B, C, D, E, F, G, cnt);
            cnt++;
            f(G, H, A, B, C, D, E, F, cnt);
            cnt++;
            f(F, G, H, A, B, C, D, E, cnt);
            cnt++;
            f(E, F, G, H, A, B, C, D, cnt);
            cnt++;
            f(D, E, F, G, H, A, B, C, cnt);
            cnt++;
            f(C, D, E, F, G, H, A, B, cnt);
            cnt++;
            f(B, C, D, E, F, G, H, A, cnt);
            cnt++;
        }

        A += AA;
        B += BB;
        C += CC;
        D += DD;
        E += EE;
        F += FF;
        G += GG;
        H += HH;

    }

    stringstream output;


    output<<dec_to_hex(A);
    output<<dec_to_hex(B);
    output<<dec_to_hex(C);
    output<<dec_to_hex(D);
    output<<dec_to_hex(E);
    output<<dec_to_hex(F);
    output<<dec_to_hex(G);
    output<<dec_to_hex(H);

    return output.str();
}

int main()
{
    string input = "hello world";
    //string input = "A quick brown fox has jumped over the lazy fox";

    string hash_value = SHA_512(input);

    cout<<"Input: "<<input<<endl;

    cout<<"Hash Value: "<<hash_value<<endl;
}
