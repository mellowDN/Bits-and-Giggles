// the following code is a simple C++ program written in Sanskrit-like syntax

#ifndef SANSKRIT_H
#define SANSKRIT_H
#include <bits/stdc++.h>
using namespace std;

//keywords
#define आरम्भ int main()
#define समाप्ति return 0;

//data types
#define संख्या int
#define दशमलव float
#define दीर्घ double
#define अक्षर char
#define वाक्य string
#define शून्य void
//input/ output
#define कथय(x) cout << x << endl;
#define छाप cout <<
#define तथा <<
#define नूतनपंक्ति << endl;
#define लेख(x) cin >> x;

//control flow
#define यदि if
#define अन्यथा else
#define यावत while
#define चक्र for

//containers
#define सूचि vector
#define योजय push_back

//operators
#define योग +
#define गुण *
#define अंतर -
#define भाग /
#define शेष %

#endif

आरम्भ
{
    संख्या अ = 5 योग 3;
    संख्या ब;
    लेख(ब);

    यदि (अ > ब) {
        कथय("अ ब से बृहत्तरः अस्ति");
    } अन्यथा {
        कथय("ब अ से बृहत्तरः अस्ति");
    }

    सूचि<संख्या> सङ्ख्याः;
    सङ्ख्याः.योजय(अ);
    सङ्ख्याः.योजय(ब);

    कथय("सूचि आकारः = " << सङ्ख्याः.size());
    समाप्ति
}

