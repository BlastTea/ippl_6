#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

// --------- Helper ----------
string formatWithComma(long long n) {
    string s = to_string(n);
    string out;
    int count = 0;
    for (int i = (int)s.size() - 1; i >= 0; --i) {
        out.push_back(s[i]);
        ++count;
        if (count == 3 && i != 0) {
            out.push_back(',');
            count = 0;
        }
    }
    reverse(out.begin(), out.end());
    return out;
}

// 1) Validasi Umur: 18 <= age <= 60
bool isValidAge(int age) {
    return age >= 18 && age <= 60;
}

// 2) Validasi Nilai Ujian: 0 <= score <= 100
bool isValidScore(int score) {
    return score >= 0 && score <= 100;
}

// 3) Validasi Panjang Password: 8 <= |pw| <= 16
bool isValidPassword(const string& pw) {
    size_t L = pw.length();
    return L >= 8 && L <= 16;
}

// 4) Validasi Harga Produk: 1.000 <= price <= 10.000.000
bool isValidPrice(long long price) {
    return price >= 1000 && price <= 10000000;
}

int main() {
    // ===================== 1. Validasi Umur =====================
    cout << "1. Validasi Umur 18-60\n";
    cout << "Equivalence Class Testing (ECT) untuk Validasi Umur 18-60\n";
    cout << "---------------------------------------------------------\n";

    vector<pair<string, int>> ageCases = {
        {"Invalid (<18)", 10},
        {"Valid (18-60)", 25},
        {"Invalid (>60)", 70}
    };

    for (const auto& tc : ageCases) {
        const string& desc = tc.first;
        int value = tc.second;
        string result = isValidAge(value) ? "VALID" : "INVALID";
        cout << "Test Case: " << desc
            << " | Umur: " << value
            << " --> Hasil: " << result << '\n';
    }

    cout << "=======================\n";

    // ===================== 2. Validasi Nilai Ujian =====================
    cout << "2. Validasi Nilai Ujian 0-100\n";
    cout << "Equivalence Class Testing (ECT)\n";
    cout << "--------------------------------\n";

    vector<pair<string, int>> scoreCases = {
        {"Invalid Rendah", -5},
        {"Valid", 85},
        {"Invalid Tinggi", 150}
    };

    for (const auto& tc : scoreCases) {
        const string& desc = tc.first;
        int value = tc.second;
        string result = isValidScore(value) ? "VALID" : "INVALID";
        cout << desc
            << " | Nilai: " << value
            << " --> " << result << '\n';
    }

    cout << "=======================\n";

    // ===================== 3. Validasi Panjang Password =====================
    cout << "3. Validasi Panjang Password 8-16 Karakter\n";
    cout << "Equivalence Class Testing (ECT)\n";
    cout << "-----------------------------------------\n";

    vector<pair<string, string>> pwCases = {
        {"Invalid Pendek", "abc123"},
        {"Valid", "secure123"},
        {"Invalid Panjang", "superlongpassword123"}
    };

    for (const auto& tc : pwCases) {
        const string& desc = tc.first;
        const string& pw = tc.second;
        string result = isValidPassword(pw) ? "VALID" : "INVALID";
        cout << desc
            << " | '" << pw << "'"
            << " (panjang = " << pw.length() << ")"
            << " --> " << result << '\n';
    }

    cout << "=======================\n";

    // ===================== 4. Validasi Harga Produk =====================
    cout << "4. Validasi Harga Produk Rp1.000 - Rp10.000.000\n";
    cout << "Equivalence Class Testing (ECT)\n";
    cout << "--------------------------------\n";

    vector<pair<string, long long>> priceCases = {
        {"Invalid Rendah", 500},
        {"Valid", 50000},
        {"Invalid Tinggi", 20000000}
    };

    for (const auto& tc : priceCases) {
        const string& desc = tc.first;
        long long value = tc.second;
        string result = isValidPrice(value) ? "VALID" : "INVALID";
        cout << desc
            << " | Harga: Rp " << formatWithComma(value)
            << " --> " << result << '\n';
    }

    return 0;
}
