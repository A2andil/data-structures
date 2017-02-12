//in the name of God

#include <iostream>
using namespace std;

class Fenwick {
private:
        int *BITree;
public:
        Fenwick(int sz, int *arr) {
                BITree = new int[sz + 1];
                for (int i = 1; i <= sz; i++)
                        BITree[i] = 0;
                for (int i = 0; i < sz; i++)
                        UpdateBIT(sz, i, arr[i]);

        }
        int GetSum(int index) {
                int rs = 0;
                index = index + 1;
                while (index > 0) {
                        rs += BITree[index];
                        index -= index & (-index);
                }
                return rs;
        }
        void UpdateBIT(int n, int index, int val) {
                index = index + 1;
                while (index <= n) {
                        BITree[index] += val;
                        index += index & (-index);
                }
        }

};

int main() {
        int arr[] = { 2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9 };
        int n = sizeof(arr) / sizeof(int);
        Fenwick *BIT = new Fenwick(n, arr);
        cout << "Sum of elements in arr[0..5] is " << BIT->GetSum(5) << endl;
        arr[3] += 6;
        BIT->UpdateBIT(n, 3, 6);
        cout << "Sum of elements in arr[0..5] is " << BIT->GetSum(5) << endl;
        return 0;
}
