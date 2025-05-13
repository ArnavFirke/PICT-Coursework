#include <bits/stdc++.h>
using namespace std;
class medical
{
    map<string, vector<string>> tests;
    vector<string> suggested;

public:
    medical()
    {
        tests = {
            {"Blood Test", {"fatigue", "fever", "weakness", "nausea"}},
            {"X-Ray", {"fracture", "injury", "pain", "swelling"}},
            {"MRI", {"headache", "dizziness", "vision problems", "nausea"}},
            {"Ultrasound", {"abdominal pain", "pregnancy", "organ examination", "bloating"}},
            {"ECG", {"chest pain", "heart palpitations", "shortness of breath", "fatigue"}},
            {"Stress Test", {"chest pain", "shortness of breath", "dizziness", "fatigue"}},
            {"Colonoscopy", {"rectal bleeding", "change in bowel habits", "abdominal pain", "bloating"}},
            {"Endoscopy", {"difficulty swallowing", "abdominal pain", "heartburn", "nausea"}},
            {"CT Scan", {"headache", "nausea", "vomiting", "dizziness"}},
            {"Spirometry", {"shortness of breath", "wheezing", "coughing", "chest tightness"}},
            {"Allergy Testing", {"itchy eyes", "sneezing", "hives", "runny nose"}},
            {"Blood Pressure Monitoring", {"dizziness", "headache", "blurry vision", "fatigue"}},
            {"Skin Biopsy", {"skin rash", "lesions", "itchiness", "redness"}},
            {"Thyroid Function Test", {"fatigue", "weight gain", "dry skin", "hair loss"}},
            {"Lung Function Test", {"shortness of breath", "coughing", "wheezing", "chest pain"}}};
    }
    void sugggest(vector<string> sysmptoms)
    {
        for (auto test : tests)
        {
            int count = 0;
            bool sug = false;
            for (string sysmptom : sysmptoms)
            {
                if (find(test.second.begin(), test.second.end(), sysmptom) != test.second.end())
                {
                    count++;
                    // suggested.push_back(test.first);
                }
            }
            if (count >= (sysmptoms.size() / 2) + 0.5)
                suggested.push_back(test.first);
        }
    }
    void print()
    {
        for (string test : suggested)
        {
            cout << test << endl;
        }
    }
};
int main()
{
    medical m;
    cout << "enter sysmptoms: ";
    vector<string> sys{"dizziness", "fatigue", "fever"};
    m.sugggest(sys);
    m.print();
    return 0;
}