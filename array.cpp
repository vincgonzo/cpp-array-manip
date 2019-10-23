#include <iostream>
#include <string>

#include <vector>

#include <bits/stdc++.h>
using namespace std;


bool answerQ()
{
    string r;
    cout << " Answer me : yes or no ? ";
    cin >> r;
    if(r == "y" || r == "yes")
    {
        return true;
    }
    return false;
}

template <typename DS>
void displayValues(vector<DS> &v33)
{
    cout << endl;
    cout << "-------------------------" << endl;
    cout << "-------- Display --------" << endl;
    cout << "-------------------------" << endl;
    for(unsigned i = 0; i < v33.size();++i)
    {
        cout << "vector index is :: " << i << " - value = " << v33[i] << endl;
    }
    cout << "-----------------------" << endl;
}

template <typename CL>
void cyclicLeftPermutation (vector<CL> &v3)
{
    CL lastIndex = v3.back();
    bool r;
    vector<CL> temp = v3;

    cout << "::: launch cyclePermutationLeft Function ::::" << endl;
    r = answerQ();
    if(r)
    {
        for(unsigned i = 0; i < temp.size();++i)
        {
            if(i == lastIndex)
            {
                v3[i] = temp[0];
            }
            else
            {
                v3[i] = temp[i+1];
            }
        }
        displayValues(v3);
    }

    return;
}

template <typename CR>
void cyclicRightPermutation (vector<CR> &v2)
{
    CR lastIndex = v2.back();
    bool r;
    vector<CR> temp = v2;

    cout << ":::: launch cyclePermutationRight Function ::::" << endl;
    r = answerQ();
    if(r)
    {
        for(unsigned i = 0; i < temp.size();++i)
        {
            if(i == 0)
            {
                v2[i] = temp[lastIndex];
            }
            else
            {
                v2[i] = temp[i-1];
            }
        }
        displayValues(v2);
    }

    return;
}

template <typename CR>
void vProfRightPermutation (vector<CR> &v2)
{
    if(!v2.empty())
    {
        CR tmp = v2.back();

        for(unsigned k = v2.back(); k > 0;--k)
            v2[k] = v2[k-1];
        v2[0] = tmp;
    }

    return;
}

template <typename RV>
void revertVector (vector<RV> &v1)
{
    RV inverseIndex = 0;
    bool r;
    vector<RV> temp = v1;

    cout << ":::: launch revertVector Function ::::" << endl;
    r = answerQ();
    if(r)
    {
        for(unsigned i = 0; i < temp.size();++i)
        {
            inverseIndex = temp.size() - (i + 1);
            v1[i] = temp[inverseIndex];
        }

        displayValues(v1);
    }

    return;
}

template <typename ERASE_E>
void eraseElement(vector<ERASE_E> &v4, ERASE_E x = 0)
{
    string response;
    bool r;
    ERASE_E val = x, i;

    cout << ":::: launch erase Function ::::" << endl;
    if(val == 0)
    {
        cout << "Are you sure you want to delete a index of current vector ?." << endl;
    }
    else
    {
        cout << "============================  /!\ WARNING ============================" << endl;
        cout << "Are you sure you want to delete all " << val << " of current vector ?." << endl;
        cout << "======================================================================" << endl;
    }

    r = answerQ();
    if(r)
    {
        if(val == 0)
        {
            cout << "which index you want to erase ? Max value (" << v4.size() << ");";
            cin >> val;
            if(val <= (v4.back()))
            {
                cout << "erase of index : " << val << " in vector __ value = " << v4[val] << ";" << endl;
                v4.erase(v4.begin() + val);
            }
        }
        else
        {
            for(i=0;i < v4.size(); ++i)
            {
                if(v4[i] == val)
                {
                    v4.erase(v4.begin() + i);
                }
            }
        }
        displayValues(v4);
    }

    return;
}

template <typename DA>
void displayAddress(vector<DA> const &v22)
{
    cout << "=========================" << endl;
    //cout << "Le vecteur est en " << &v22 << endl;
     for(unsigned i = 0; i < v22.size();++i)
    {
//        v[i] = i + 1;
        cout << "vector index is :: " << i << "value " << v22[i] <<" - address = " << &v22[i] << endl;
    }
    cout << "=========================" << endl;

    return;
}

void eraseDouble(vector<double> &v33)
{
    vector<double> tmp;

    for(unsigned i = 0; i < v33.size();++i)
    {
        if ( std::find(tmp.begin(), tmp.end(), v33[i]) != tmp.end() )
           v33.erase(v33.begin() + i);
        else
           tmp.push_back(v33[i]);
    }
    displayAddress(v33);
    displayValues(v33);
}

int main()
{

    //std::vector<int> v1 [10] = {6, 3, 2, -8, 9};

    //vector<int> v(5);
    vector<int> v {6, 3, 2, -8, 9, 8, 15, 4, 3, 7};
    vector<double> n {0.5, 1.5, 2.5, 1.5, 3.5, 1.5, 2.5, 4.5};

    //displayAddress(v);

    displayValues(v);

    // Complete revert of a array
    //revertVector(v);
    //revertVector(n);

    // One change allocation to right
    cyclicRightPermutation(v);
    displayValues(v);
    vProfRightPermutation(v);
    displayValues(v);
/*
    // One change allocation to left
    cyclicLeftPermutation(v);


    // Erase element on target array
    eraseElement(v);
    eraseElement(v, 8);
    displayValues(v);
    eraseElement(v, 3);
    displayValues(v);
    */
    //displayValues(n);
    displayAddress(n);
    eraseDouble(n);

}

