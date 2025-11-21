#include<iostream>
#include<vector>

int main()
{
    std::vector<int> my_vector;
    for(int i=0;i<5;i++)
        my_vector.push_back(i);

    for(auto& i: my_vector)
        std::cout << my_vector[i] << " " ; 

    return 0;
}