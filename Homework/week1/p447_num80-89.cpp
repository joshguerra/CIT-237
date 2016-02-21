// 80. 
// int size;
// double values[size];
int const SIZE;
double values[SIZE];

// 81. 
// int collection[-20];
int collection[20];

// 82. 
// int table[10];
// for (int x = 0; x < 20; x++)
// {
// cout << "Enter the next value: ";
// cin >> table[x];
// }

int table[10];
for (int x = 0; x < 10; x++) {
    cout << "Enter the next value: ";
    cin >> table[x];
}

// 83. 
// int hours[3] = 8, 12, 16;
int hours[3] = {8, 12, 16};

// 84. 
// int numbers[8] = {1, 2, , 4, , 5};
int numbers[8] = {1, 2, 0, 4, 0, 5};
// numbers[6] and numbers[7] will be zero

// 85. 
// float ratings[];
float ratings[] = {1, 2, 3, 4};
// if array size is not declared, then array must be intitialized  

// 86. 
// char greeting[] = {'H', 'e', 'l', 'l', 'o'};
// cout << greeting;
// nothing is wrong with this code. it compiles and runs as expected
// though, I would have made a loop to print each character

// 87. 
// int array1[4], array2[4] = {3, 6, 9, 12};
// array1 = array2;
int array1[4], array2[4] = {3, 6, 9, 12};
for (int i = 0; i < 4; i++)
    array1[i] = array2[i];

// 88. 
// void showValues(int nums)
// {
// for (int count = 0; count < 8; count++)
// cout << nums[count];
// }
void showValues(int nums[]) {
    for (int count = 0; count < 8; count++)
        cout << nums[count];
}

// 89. 
// void showValues(int nums[4][])
// {
//     for (rows = 0; rows < 4; rows++)
//         for (cols = 0; cols < 5; cols++)
//             cout << nums[rows][cols];
// }
void showValues(int nums[4][]) {
    for (int rows = 0; rows < 4; rows++)
        for (int cols = 0; cols < 5; cols++)
            cout << nums[rows][cols];
}