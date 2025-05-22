
#include <iostream>
#include <string>
using namespace std;

class TinhCach {
protected:
    int chisodiem;
    string tenTC;
public:
    TinhCach(int diem = 0, string ten = "") : chisodiem(diem), tenTC(ten) {}
    virtual void nhap() {
        cout << "Nhap diem " << tenTC << ": ";
        cin >> chisodiem;
    }
    virtual void xuat() = 0;
    int layDiem() const { return chisodiem; }
    string layTen() const { return tenTC; }
    virtual ~TinhCach() {}
};

class O : public TinhCach {
public:
    O(int d = 0) : TinhCach(d, "O") {}
    void xuat() override {
        cout << chisodiem << " Sẵn sàng trải nghiệm (O): ";
        if (chisodiem >= 70)
            cout << "Thích ý tưởng mới, tự do." << endl;
        else if (chisodiem <= 30)
            cout << "Bảo thủ, thực tế." << endl;
        else cout << "Không xác định rõ." << endl;
    }
};

class C : public TinhCach {
public:
    C(int d = 0) : TinhCach(d, "C") {}
    void xuat() override {
        cout << chisodiem << " Tự chủ tận tâm (C): ";
        if (chisodiem >= 70)
            cout << "Chăm chỉ, tuân thủ tổ chức." << endl;
        else if (chisodiem <= 30)
            cout << "Thiếu trách nhiệm, dễ bỏ cuộc." << endl;
        else cout << "Không xác định rõ." << endl;
    }
};

class E : public TinhCach {
public:
    E(int d = 0) : TinhCach(d, "E") {}
    void xuat() override {
        cout << chisodiem << " Hướng ngoại (E): ";
        if (chisodiem >= 70)
            cout << "Năng động, giao tiếp tốt." << endl;
        else if (chisodiem <= 30)
            cout << "Ngại giao tiếp, kín đáo." << endl;
        else cout << "Không xác định rõ." << endl;
    }
};

class A : public TinhCach {
public:
    A(int d = 0) : TinhCach(d, "A") {}
    void xuat() override {
        cout << chisodiem << " Hòa đồng (A): ";
        if (chisodiem >= 70)
            cout << "Thân thiện, đồng cảm." << endl;
        else if (chisodiem <= 30)
            cout << "Ích kỷ, cạnh tranh." << endl;
        else cout << "Không xác định rõ." << endl;
    }
};

class N : public TinhCach {
public:
    N(int d = 0) : TinhCach(d, "N") {}
    void xuat() override {
        cout << chisodiem << " Bất ổn cảm xúc (N): ";
        if (chisodiem >= 70)
            cout << "Lo âu, dễ bị tổn thương." << endl;
        else if (chisodiem <= 30)
            cout << "Kiểm soát cảm xúc tốt." << endl;
        else cout << "Không xác định rõ." << endl;
    }
};

class People {
    string hoten;
    int tuoi;
    TinhCach* tc[5];
public:
    People() {
        for (int i = 0; i < 5; i++) tc[i] = nullptr;
    }

    void nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore(); getline(cin, hoten);
        cout << "Nhap tuoi: "; cin >> tuoi;

        int diem;
        cout << "Nhap diem O C E A N: ";
        cin >> diem; tc[0] = new O(diem);
        cin >> diem; tc[1] = new C(diem);
        cin >> diem; tc[2] = new E(diem);
        cin >> diem; tc[3] = new A(diem);
        cin >> diem; tc[4] = new N(diem);
    }

    void xuat() {
        cout << "\nHo ten: " << hoten << ", Tuoi: " << tuoi << endl;
        for (int i = 0; i < 5; i++) tc[i]->xuat();
    }

    bool coNguyCo() {
        int c = tc[1]->layDiem();
        int e = tc[2]->layDiem();
        int n = tc[4]->layDiem();
        return (c <= 30 || n >= 70 || (e <= 30 && n >= 70));
    }

    string layTen() { return hoten; }

    ~People() {
        for (int i = 0; i < 5; i++) delete tc[i];
    }
};

class DSPeople {
    People* ds[100];
    int soluong;
public:
    DSPeople() { soluong = 0; }

    void nhap() {
        cout << "Nhap so luong nguoi: ";
        cin >> soluong;
        for (int i = 0; i < soluong; i++) {
            cout << "\nNguoi thu " << i + 1 << ":" << endl;
            ds[i] = new People();
            ds[i]->nhap();
        }
    }

    void xuat() {
        for (int i = 0; i < soluong; i++) {
            cout << "\n== Nguoi thu " << i + 1 << " ==";
            ds[i]->xuat();
        }
    }

    void timCoNguyCo() {
        cout << "\nNguoi co nguy co cao:\n";
        for (int i = 0; i < soluong; i++)
            if (ds[i]->coNguyCo())
                cout << "- " << ds[i]->layTen() << endl;
    }

    ~DSPeople() {
        for (int i = 0; i < soluong; i++) delete ds[i];
    }
};

int main() {
    DSPeople d;
    d.nhap();
    d.xuat();
    d.timCoNguyCo();
    return 0;
}
