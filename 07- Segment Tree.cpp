//in the name of God

#include <iostream>
#include <cmath>

#define ll long long
using namespace std;

class SegmentTree {
private:
        int *ST;
        int Pow(int b, int n) {
                if (!n) return 1;
                int rs = Pow(b, n / 2);
                return n % 2 ? rs * rs * b : rs * rs;
        }
        void UpdateValueUtil(int ss, int se, int i, int dif, int si) {
                if (i < ss || i > se)
                        return;
                ST[si] = ST[si] + dif;
                if (se != ss) {
                        int md = ss + (se - ss) / 2;
                        UpdateValueUtil(ss, md, i, dif, 2 * si + 1);
                        UpdateValueUtil(md + 1, se, i, dif, 2 * si + 2);
                }
        }
        int BuildSTUtil(int *list, int s, int e, int i) {
                if (s == e) {
                        ST[i] = list[s];
                        return list[s];
                }
                int md = s + (e - s) / 2;
                ST[i] = BuildSTUtil(list, s, md, i * 2 + 1) +
                        BuildSTUtil(list, md + 1, e, i * 2 + 2);
                return ST[i];
        }
        int GetSumUtil(int ss, int se, int qs, int qe, int si) {
                if (qs <= ss && qe >= se)
                        return ST[si];
                if (se < qs || ss > qe)
                        return 0;
                int md = ss + (se - ss) / 2;
                return GetSumUtil(ss, md, qs, qe, 2 * si + 1) +
                        GetSumUtil(md + 1, se, qs, qe, 2 * si + 2);
        }
public:
        SegmentTree(int *list, int n) {
                int sz = 2 * Pow(2, ceil(log2(n))) - 1;
                ST = new int[sz];
                BuildSTUtil(list, 0, n - 1, 0);
        }
        int GetSum(int n, int s, int e) {
                if (s < 0 || e > n - 1 || s > e) {
                        printf("Invalid Input");
                        return -1;
                }
                return GetSumUtil(0, n - 1, s, e, 0);
        }
        void UpdateValue(int *list, int n, int i, int value) {
                if (i < 0 || i > n - 1) {
                        printf("Invalid Input");
                        return;
                }
                int dif = value - list[i];
                list[i] = value;
                UpdateValueUtil(0, n - 1, i, dif, 0);
        }
};

int main() {
        int list[] = { 1, 3, 5, 7, 9, 11 };
        int n = sizeof(list) / sizeof(int);
        SegmentTree *STree = new SegmentTree(list, n);
        cout << "Sum of values in given range = " << STree->GetSum(n, 1, 3) << endl;
        STree->UpdateValue(list, n, 1, 9);
        cout << "sum of values in given range = " << STree->GetSum(n, 1, 3) << endl;
        return 0;
}
