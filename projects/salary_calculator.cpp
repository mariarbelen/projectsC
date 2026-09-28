//Maria Rodriguez 
//  Programming Project 
//CS002 - Fundamentals of Computer Science 


#include <iostream>


const double SOCIAL_SECURITY = 0.062,
  FEDERAL_INCOME = 0.22,
  MEDICARE_TAX = 0.0145;
int grossSalary;

int main() {
    using namespace std;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    cout << "Enter the gross salary to get net salary ";
    cin >> grossSalary;

    int choice;
    int socialSecurityAmount;
    int federalIncomeAmount;
    int medicareAmount;
    double healthInsuranceDeducation;
    int taxableIncome;
    int totaldeducateSalary;
    int pensionPlan;
    double visionInsuranceDeducation;
    double dentalInsuranceSelf;
    double dentalInsuranceDeducation;
    int netSalary;

    cout << "Yearly Breakdown, Monthly, Bi Monthly, or Weekly " <<
      "\n1 - Weekly " <<
      "\n2 - Monthly " <<
      "\n3 - Bi Monthly " <<
      "\n4 - Yearly" << endl;

    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            socialSecurityAmount = (grossSalary / 52) * SOCIAL_SECURITY;
            federalIncomeAmount = (grossSalary / 52) * FEDERAL_INCOME;
            medicareAmount = (grossSalary / 52) * MEDICARE_TAX;

            char choice;
            cout << "Do you want health insurance";
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
              cout << "Do you want health insurance for (y)ourself or yourself and (o)thers? ";
              cin >> choice;
              if (choice == 'O' || choice == 'o') {
                healthInsuranceDeducation = 251.63 / 8;
              }
            }
            cout << "Do you want dental insurance";
            cin >> choice;
            if (choice == 'Y' || choice == 'y') {
              dentalInsuranceSelf = 17.58 / 8;
              cout << "Do you want dental insurance for (y)ourself or yourself and (o)thers? ";

              if (choice == 'O' || choice == 'o') {
                dentalInsuranceDeducation = 70.88 / 8;
              }
            }
            break;

            case 2: {
              socialSecurityAmount = (grossSalary / 12) * SOCIAL_SECURITY;
              federalIncomeAmount = (grossSalary / 12) * FEDERAL_INCOME;
              medicareAmount = (grossSalary / 12) * MEDICARE_TAX;

              char choice;
              cout << "Do you want health insurance";
              cin >> choice;
              if (choice == 'Y' || choice == 'y') {
                cout << "Do you want health insurance for (y)ourself or yourself and (o)thers? ";
                cin >> choice;
                if (choice == 'O' || choice == 'o') {
                  healthInsuranceDeducation = 251.63 / 2;
                  char choice;
                }
              }
              cout << "Do you want dental insurance";
              if (choice == 'Y' || choice == 'y') {
                dentalInsuranceSelf = 17.58 / 2;
                cout << "Do you want dental insurance for (y)ourself or yourself and (o)thers? ";

                if (choice == 'O' || choice == 'o') {
                  dentalInsuranceDeducation = 70.88 / 2;
                }
              }
              cout << "Do you want vision insurance";
              cin >> choice;
              if (choice == 'Y' || choice == 'y') {
                cout << "Do you want health insurance for (y)ourself or yourself and (o)thers? ";
                cin >> choice;
                if (choice == 'O' || choice == 'o') {
                  visionInsuranceDeducation = 5.61 / 2;

                }
              }
              break;

              case 3: {
                socialSecurityAmount = (grossSalary / 6) * SOCIAL_SECURITY;
                federalIncomeAmount = (grossSalary / 6) * FEDERAL_INCOME;
                medicareAmount = (grossSalary / 6) * MEDICARE_TAX;

                char choice;
                cout << "Do you want health insurance";
                cin >> choice;
                if (choice == 'Y' || choice == 'y') {
                  cout << "Do you want health insurance for (y)ourself or yourself and (o)thers? ";
                  cin >> choice;
                  if (choice == 'O' || choice == 'o') {
                    healthInsuranceDeducation = 251.63;
                  }
                }
                cout << "Do you want dental insurance";
                cin >> choice;
                if (choice == 'Y' || choice == 'y') {
                  dentalInsuranceSelf = 17.58;
                  cout << "Do you want dental insurance for (y)ourself or yourself and (o)thers? ";

                  if (choice == 'O' || choice == 'o') {
                    dentalInsuranceDeducation = 70.88;
                  }
                }
                cout << "Do you want vision insurance";
                cin >> choice;
                if (choice == 'Y' || choice == 'y') {
                  cout << "Do you want vision insurance for (y)ourself or yourself and (o)thers? ";
                  cin >> choice;
                  if (choice == 'O' || choice == 'o') {
                    visionInsuranceDeducation = 5.61;

                    break;
                    case 4: {
                      socialSecurityAmount = grossSalary * SOCIAL_SECURITY;
                      federalIncomeAmount = grossSalary * FEDERAL_INCOME;
                      medicareAmount = grossSalary * MEDICARE_TAX;

                      char choice;
                      cout << "Do you want health insurance";
                      cin >> choice;
                      if (choice == 'Y' || choice == 'y') {
                        cout << "Do you want health insurance for (y)ourself or yourself and (o)thers? ";
                        cin >> choice;
                        if (choice == 'O' || choice == 'o') {
                          healthInsuranceDeducation = 251.63 * 6;
                        }
                      }
                      cout << "Do you want dental insurance";
                      cin >> choice;
                      if (choice == 'Y' || choice == 'y') {
                        dentalInsuranceSelf = 17.58 * 6;
                        cout << "Do you want dental insurance for (y)ourself or yourself and (o)thers? ";

                        if (choice == 'O' || choice == 'o') {
                          dentalInsuranceDeducation = 70.88 * 6;
                        }
                      }
                      cout << "Do you want vision insurance";
                      cin >> choice;
                      if (choice == 'Y' || choice == 'y') {
                        cout << "Do you want vision insurance for (y)ourself or yourself and (o)thers? ";
                        
                        if (choice == 'O' || choice == 'o') {
                          visionInsuranceDeducation = 5.61 * 6;
                        }
                      }
                      break;
                      default: break;
                    }

                    if (grossSalary <= 8544) {
                      taxableIncome = 0.001 * totaldeducateSalary;
                    } else if (grossSalary > 8545 && grossSalary < 20255) {
                      taxableIncome = 0.002 * totaldeducateSalary;
                    } else if (grossSalary > 20256 && grossSalary < 31969) {
                      taxableIncome = 0.004 * totaldeducateSalary;
                    } else if (grossSalary > 31970 && grossSalary < 44377) {
                      taxableIncome = 0.006 * totaldeducateSalary;
                    } else if (grossSalary > 44378 && grossSalary < 56085) {
                      taxableIncome = 0.006 * totaldeducateSalary;
                    } else if (grossSalary > 56086 && grossSalary < 286492) {
                      taxableIncome = 0.093 * totaldeducateSalary;
                    } else if (grossSalary > 286493 && grossSalary < 343788) {
                      taxableIncome = 0.103 * totaldeducateSalary;
                    } else if (grossSalary > 343789 && grossSalary < 572980) {
                      taxableIncome = 0.113 * totaldeducateSalary;
                    } else if (grossSalary > 572981 && grossSalary < 999999) {
                      taxableIncome = 0.123 * totaldeducateSalary;
                    } else if (grossSalary > 1000000) {
                      taxableIncome = 0.133 * totaldeducateSalary;
                    }


                    cout << " What percentage of pension plan would you like ";
                    cout << pensionPlan;
                    pensionPlan = pensionPlan / 100;

                    cout<< "Gross Salary:" << grossSalary<< endl;
                    cout<< "Social Security:"<< socialSecurityAmount<< endl;
                    cout<< "Federal Income Tax: " << federalIncomeAmount <<endl;
                    cout <<"Pension plan:" << pensionPlan<< endl;
                    cout <<" Medicare Tax:" << medicareAmount <<endl;
                    cout <<"Health Insurance  "<< healthInsuranceDeducation << endl;
                    cout << "Dental Insurance " << dentalInsuranceDeducation << endl;
                    cout<< "Net Salary" << netSalary << endl;

                    double netSalary = grossSalary - socialSecurityAmount - federalIncomeAmount - medicareAmount - taxableIncome - pensionPlan
                    - healthInsuranceDeducation- visionInsuranceDeducation - dentalInsuranceDeducation; 

                  }
                  return 0;
                    }
                    }
            }
        }
      }
}

