//make one function for diagnosis which will itself call function for appointment or not, tests, and print receipts and payment
//this one function will also have all the symptom functions declared inside it


#include<iostream>
#include<string>
#include<limits>
#include<fstream>
#include<conio.h>
#include<ctime>
#include<chrono>
#include<thread>
using namespace std;
string password;
	struct record {
		string name;
		string DOB;
		string gender;
		string CNIC;
		string MaritalStatus;
		string address;
		string phone;
		string email;
		string emergencyname;
		string emergencyrelation;
		string emergencyphone;
		string allergies;
		string medication;
		string surgeries;
		string employment;
		string employer;
		string workaddress;

	};
bool isTimeWithinRange(int startHour, int endHour) {
    time_t currentTime = chrono::system_clock::to_time_t(chrono::system_clock::now());
    struct tm* timeinfo = localtime(&currentTime);

    int currentHour = timeinfo->tm_hour;

    return (currentHour >= startHour && currentHour < endHour);
}
void PrintForm(int position){
	ifstream CNICRecords;
	CNICRecords.open("cnicrecord.txt", ios::in);
	ifstream Records;
	Records.open("record.txt",ios::in);
	int currentline=1;
	string line;
	while(getline(CNICRecords,line)&& currentline<position){
						++currentline;
					}
					
			string searchCNIC=line;		
			CNICRecords.close();
			string recordsposition;
	while(getline(Records,recordsposition)){
	
		
		if(recordsposition==searchCNIC){
			
			break;
		}
	}		
	   
		
         	cout<<"Full Name:"<<endl;
         	string patientname;
			getline(Records,patientname);
			cout<<patientname<<endl;
		    cout<<"Date Of Birth:"<<endl;
		    string patientDOB;
			getline(Records,patientDOB);
			cout<<patientDOB<<endl;
			cout<<"Gender:"<<endl;
			string patientgender;
			getline(Records,patientgender);
			cout<<patientgender<<endl;
			cout<<"Marital Status:"<<endl;
			string patientMaritalStatus;
			getline(Records,patientMaritalStatus);
			cout<<patientMaritalStatus<<endl;
			cout<<"2) CONTACT DETAILS"<<endl;
			cout<<"Address:"<<endl;
			string patientaddress;
			getline(Records,patientaddress);
			cout<<patientaddress<<endl;
			cout<<"Phone Number:"<<endl;
			string patientphone;
			getline(Records,patientphone);
			cout<<patientphone<<endl;
			cout<<"Email Address:"<<endl;
			string patientemail;
			getline(Records,patientemail);
			cout<<patientemail<<endl;
			cout<<"3) EMERGENCY CONTACT"<<endl;
			cout<<"Name:"<<endl;
			string patientemergencyname;
			getline(Records,patientemergencyname);
			cout<<patientemergencyname<<endl;
			cout<<"Relationship:"<<endl;
			string patientemergencyrelation;
			getline(Records,patientemergencyrelation);
			cout<<patientemergencyrelation<<endl;
			cout<<"Phone Number:"<<endl;
			string patientemergencyphone;
			getline(Records,patientemergencyphone);
		    cout<<patientemergencyphone<<endl;
			cout<<"4) MEDICAL HISTORY"<<endl;
			cout<<"Allergies:"<<endl;
			string patientallergies;
			getline(Records,patientallergies);
			cout<<patientallergies<<endl;
			cout<<"Current Medication:"<<endl;
			string patientmedication;
			getline(Records,patientmedication);
			cout<<patientmedication<<endl;
			cout<<"Past Surgeries:"<<endl;
			string patientsurgeries;
			getline(Records,patientsurgeries);
			cout<<patientsurgeries<<endl;
			cout<<"5) OCCUPATION"<<endl;
            cout<<"Employment Status:"<<endl;
            string  patientemployment;
			getline(Records,patientemployment);
			cout<<patientemployment<<endl;
            cout<<"Employer's Name:"<<endl;
            string patientemployer;
			getline(Records,patientemployer);
			cout<<patientemployer<<endl;
            cout<<"Work Address:"<<endl;
            string patientworkaddress;
            getline(Records,patientworkaddress);
            cout<<patientworkaddress<<endl;
	
          Records.close();
      cout<<"press any key to continue"<<endl;
	  getch();
	  system("cls");        
	
}
void PersonalInformationForm(){

    ofstream RecordSaving;
    RecordSaving.open("record.txt",ios::app);
    ofstream CNICSaving;
    CNICSaving.open("cnicrecord.txt",ios::app);
    ifstream CNICMatching;
    CNICMatching.open("cnicrecord.txt",ios::in);
    ofstream PasswordSaving;
    PasswordSaving.open("passwords.txt",ios::app);
	record patient;
	        cout<<"1) PERSONAL INFORMATION"<<endl;
	        cout<<"CNIC identification number:"<<endl;
	        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			getline(cin,patient.CNIC);
			bool exists;
			exists=false;
			string checkcondition;
			while(!CNICMatching.eof()){
				string check;
				getline(CNICMatching, check);
				if(check==patient.CNIC){
					exists=true;
					checkcondition=check;
					break;
				}
			}
			if(exists==true){
				while(checkcondition==patient.CNIC){
				cout<<"this CNIC is already registered, try again:"<<endl;
				getline(cin,patient.CNIC);
				
			}
			
			}
			cout<<"Enter a password"<<endl;
			getline(cin,password);
			PasswordSaving<<password<<"\r\n";
			CNICSaving<<patient.CNIC<<"\r\n";
			RecordSaving<<patient.CNIC<<"\r\n";
			cout<<"Full Name:"<<endl;
			getline(cin,patient.name);
			RecordSaving<<patient.name<<"\r\n";
		    cout<<"Date Of Birth:"<<endl;
			getline(cin,patient.DOB);
			RecordSaving<<patient.DOB<<"\r\n";
			cout<<"Gender:"<<endl;
			getline(cin,patient.gender);
			RecordSaving<<patient.gender<<"\r\n";
			cout<<"Marital Status:"<<endl;
			getline(cin,patient.MaritalStatus);
			RecordSaving<<patient.MaritalStatus<<"\r\n";
			cout<<"2) CONTACT DETAILS"<<endl;
			cout<<"Address:"<<endl;
			getline(cin,patient.address);
			RecordSaving<<patient.address<<"\r\n";
			cout<<"Phone Number:"<<endl;
			getline(cin,patient.phone);
			RecordSaving<<patient.phone<<"\r\n";
			cout<<"Email Address:"<<endl;
			getline(cin,patient.email);
			RecordSaving<<patient.email<<"\r\n";
			cout<<"3) EMERGENCY CONTACT"<<endl;
			cout<<"Name:"<<endl;
			getline(cin,patient.emergencyname);
			RecordSaving<<patient.emergencyname<<"\r\n";
			cout<<"Relationship:"<<endl;
			getline(cin,patient.emergencyrelation);
			RecordSaving<<patient.emergencyrelation<<"\r\n";
			cout<<"Phone Number:"<<endl;
			getline(cin,patient.emergencyphone);
			RecordSaving<<patient.emergencyphone<<"\r\n";
			cout<<"4) MEDICAL HISTORY"<<endl;
			cout<<"Allergies:"<<endl;
			getline(cin,patient.allergies);
			RecordSaving<<patient.allergies<<"\r\n";
			cout<<"Current Medication:"<<endl;
			getline(cin,patient.medication);
			RecordSaving<<patient.medication<<"\r\n";
			cout<<"Past Surgeries:"<<endl;
			getline(cin,patient.surgeries);
			RecordSaving<<patient.surgeries<<"\r\n";
			cout<<"5) OCCUPATION"<<endl;
            cout<<"Employment Status:"<<endl;
			getline(cin,patient.employment);
			RecordSaving<<patient.employment<<"\r\n";
            cout<<"Employer's Name:"<<endl;
			getline(cin,patient.employer);
			RecordSaving<<patient.employer<<"\r\n";
            cout<<"Work Address:"<<endl;
			getline(cin,patient.workaddress);
			RecordSaving<<patient.workaddress<<"\r\n";

            
			
} 
void printmatchingsymptomsAbdPain(bool arr[41], bool disease[41]){
	for(int i=0; i<41; i++){
		if(arr[i]==disease[i] && arr[i]==1){
			switch (i) {
				case 0: cout<<"pain is burning"<<endl;   break;
				case 1: cout<<"pain is crampy"<<endl;   break;
				case 2: cout<<"pain is dull"<<endl;   break;
				case 3: cout<<"pain is gnawing"<<endl;   break;
				case 4: cout<<"pain is intense"<<endl;   break;
				case 5: cout<<"pain is intermittent or episodic"<<endl;   break;
				case 6: cout<<"pain is ongoing(chronic)"<<endl;   break;
				case 7: cout<<"pain is sharp"<<endl;   break;
				case 8: cout<<"pain is steady"<<endl;   break;
				case 9: cout<<"pain is sudden"<<endl;   break;
				case 10: cout<<"pain is worsening"<<endl;   break;
				case 11: cout<<"pain is located in abdomen but radiates to other parts of the body"<<endl;   break;
				case 12: cout<<"pain is located in lower abdomen"<<endl;   break;
				case 13: cout<<"pain is located in middle abdomen"<<endl;   break;
				case 14: cout<<"pain is located in one or both sides"<<endl;   break;
				case 15: cout<<"pain is located in upper abdomen"<<endl;   break;
				case 16: cout<<"triggered or worsened by coughing or other jarring movements"<<endl;   break;
				case 17: cout<<"triggered or worsened by drinking alcohol"<<endl;   break;
				case 18: cout<<"triggered or worsened by eating certain foods"<<endl;   break;
				case 19: cout<<"triggered or worsened by menstrual cycle"<<endl;   break;
				case 20: cout<<"triggered or worsened by stress"<<endl;   break;
				case 21: cout<<"relieved by antacids"<<endl;   break;
				case 22: cout<<"relieved by avoiding certain foods"<<endl;   break;
				case 23: cout<<"relieved by changing position"<<endl;   break;
				case 24: cout<<"relieved by drinking more water"<<endl;   break;
				case 25: cout<<"relieved by eating certain foods"<<endl;   break;
				case 26: cout<<"relieved by eating more fiber"<<endl;   break;
				case 27: cout<<"accompanied by abdominal swelling"<<endl;   break;
				case 28: cout<<"accompanied by black or bloody stools"<<endl;   break;
				case 29: cout<<"accompanied by constipation"<<endl;   break;
				case 30: cout<<"accompanied by diarrhea"<<endl;   break;
				case 31: cout<<"accompanied by fever"<<endl;   break;
				case 32: cout<<"accompanied by inability to move bowels in spite of urge"<<endl;   break;
				case 33: cout<<"accompanied by loose, watery stools"<<endl;   break;
				case 34: cout<<"accompanied by nausea or vomitting"<<endl;   break;
				case 35: cout<<"accompanied by passing gas"<<endl;   break;
				case 36: cout<<"accompanied by pulsing sensation near navel"<<endl;   break;
				case 37: cout<<"accompanied by rash"<<endl;   break;
				case 38: cout<<"accompanied by stomach growling or rumbling"<<endl;   break;
				case 39: cout<<"accompanied by unintended weight loss"<<endl;   break;
				case 40: cout<<"accompanied by urgent need to have bowel movement"<<endl;   break;
			}
			
		}
	}
	
}
void printremainingsymptomsAbdPain(bool arr[41], bool disease[41]){
	
	bool remainingsymptomspresent=false;
	
	for(int i=0; i<41; i++){
		if(arr[i]!=disease[i] && disease[i]==1){
			remainingsymptomspresent=true;
		}
	}
	if(remainingsymptomspresent==true){
		cout<<"OTHER SYMPTOMS INCLUDE:"<<endl;
	
	for(int i =0; i<41; i++){
		if(arr[i]!=disease[i] && disease[i]==1){
			switch (i) {
				case 0: cout<<"pain is burning"<<endl;   break;
				case 1: cout<<"pain is crampy"<<endl;   break;
				case 2: cout<<"pain is dull"<<endl;   break;
				case 3: cout<<"pain is gnawing"<<endl;   break;
				case 4: cout<<"pain is intense"<<endl;   break;
				case 5: cout<<"pain is intermittent or episodic"<<endl;   break;
				case 6: cout<<"pain is ongoing(chronic)"<<endl;   break;
				case 7: cout<<"pain is sharp"<<endl;   break;
				case 8: cout<<"pain is steady"<<endl;   break;
				case 9: cout<<"pain is sudden"<<endl;   break;
				case 10: cout<<"pain is worsening"<<endl;   break;
				case 11: cout<<"pain is located in abdomen but radiates to other parts of the body"<<endl;   break;
				case 12: cout<<"pain is located in lower abdomen"<<endl;   break;
				case 13: cout<<"pain is located in middle abdomen"<<endl;   break;
				case 14: cout<<"pain is located in one or both sides"<<endl;   break;
				case 15: cout<<"pain is located in upper abdomen"<<endl;   break;
				case 16: cout<<"triggered or worsened by coughing or other jarring movements"<<endl;   break;
				case 17: cout<<"triggered or worsened by drinking alcohol"<<endl;   break;
				case 18: cout<<"triggered or worsened by eating certain foods"<<endl;   break;
				case 19: cout<<"triggered or worsened by menstrual cycle"<<endl;   break;
				case 20: cout<<"triggered or worsened by stress"<<endl;   break;
				case 21: cout<<"relieved by antacids"<<endl;   break;
				case 22: cout<<"relieved by avoiding certain foods"<<endl;   break;
				case 23: cout<<"relieved by changing position"<<endl;   break;
				case 24: cout<<"relieved by drinking more water"<<endl;   break;
				case 25: cout<<"relieved by eating certain foods"<<endl;   break;
				case 26: cout<<"relieved by eating more fiber"<<endl;   break;
				case 27: cout<<"accompanied by abdominal swelling"<<endl;   break;
				case 28: cout<<"accompanied by black or bloody stools"<<endl;   break;
				case 29: cout<<"accompanied by constipation"<<endl;   break;
				case 30: cout<<"accompanied by diarrhea"<<endl;   break;
				case 31: cout<<"accompanied by fever"<<endl;   break;
				case 32: cout<<"accompanied by inability to move bowels in spite of urge"<<endl;   break;
				case 33: cout<<"accompanied by loose, watery stools"<<endl;   break;
				case 34: cout<<"accompanied by nausea or vomitting"<<endl;   break;
				case 35: cout<<"accompanied by passing gas"<<endl;   break;
				case 36: cout<<"accompanied by pulsing sensation near navel"<<endl;   break;
				case 37: cout<<"accompanied by rash"<<endl;   break;
				case 38: cout<<"accompanied by stomach growling or rumbling"<<endl;   break;
				case 39: cout<<"accompanied by unintended weight loss"<<endl;   break;
				case 40: cout<<"accompanied by urgent need to have bowel movement"<<endl;   break;
			}
		}
		
	}
}
	
	
}
void matchAbdPainAdultAppendicitis(bool arr[41]){
	
	
    bool AppendicitisAns[41]={0,1,1,0,1,0,0,1,1,1,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,0,1,0,0,0,0,0,0};

	bool appendicitis=false;
	for(int i=0; i<41; i++){
		if(arr[i]==AppendicitisAns[i]){
			appendicitis=true;
			
		}
	}
	if(appendicitis==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH APPENDICITIS  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH \n";
		printmatchingsymptomsAbdPain(arr, AppendicitisAns);
		printremainingsymptomsAbdPain(arr, AppendicitisAns);
		cout<<"\n \n";
	}
}
void matchAbdPainAdultCrohns(bool arr[41]){
	 bool CrohnsAns[41]={0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,1,0,0,1,0,1,0};

	bool crohns=false;
	for(int i=0; i<41; i++){
		if(arr[i]==CrohnsAns[i]){
			crohns=true;
			
		}
	}
	if(crohns==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH CROHN'S DISEASE  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsAbdPain(arr, CrohnsAns);
		printremainingsymptomsAbdPain(arr, CrohnsAns);
		cout<<"\n \n";
	}
}
void matchAbdPainAdultCeliac(bool arr[41]){
	 bool CeliacAns[41]={0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,1,0,1,1,1,0};

	bool celiac=false;
	for(int i=0; i<41; i++){
		if(arr[i]==CeliacAns[i]){
			celiac=true;
			
		}
	}
	if(celiac==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH CELIAC DISEASE  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsAbdPain(arr, CeliacAns);
		printremainingsymptomsAbdPain(arr, CeliacAns);
		cout<<"\n \n";
	}
}
void matchAbdPainAdultIBS(bool arr[41]){
	 bool IBSAns[41]={0,1,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1,0,1,1,0,0,0,0,1,0,0,0,0,0};

	bool ibs=false;
	for(int i=0; i<41; i++){
		if(arr[i]==IBSAns[i]){
			ibs=true;
			
		}
	}
	if(ibs==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH IRRITABLE BOWEL SYNDROME  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsAbdPain(arr, IBSAns);
		printremainingsymptomsAbdPain(arr, IBSAns);
		cout<<"\n \n";
	}
}
void matchAbdPainAdultLC(bool arr[41]){
	 bool LCAns[41]={0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0};

	bool lc=false;
	for(int i=0; i<41; i++){
		if(arr[i]==LCAns[i]){
			lc=true;
			
		}
	}
	if(lc==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH LACTOSE INTOLERANCE \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsAbdPain(arr, LCAns);
		printremainingsymptomsAbdPain(arr, LCAns);
		cout<<"\n \n";
	}
}
void matchAbdPainAdultFoodPoison(bool arr[41]){
	 bool FoodPoisonAns[41]={0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,0};

	bool foodpoison=false;
	for(int i=0; i<41; i++){
		if(arr[i]==FoodPoisonAns[i]){
			foodpoison=true;
			
		}
	}
	if(foodpoison==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH FOOD POISONING  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsAbdPain(arr, FoodPoisonAns);
		printremainingsymptomsAbdPain(arr, FoodPoisonAns);
		cout<<"\n \n";
	}
}
void matchAbdPainAdultEndometriosis(bool arr[41]){
	 bool EndoAns[41]={0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

	bool endo=false;
	for(int i=0; i<41; i++){
		if(arr[i]==EndoAns[i]){
			endo=true;
			
		}
	}
	if(endo==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH ENDOMETRIOSIS  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsAbdPain(arr, EndoAns);
		printremainingsymptomsAbdPain(arr, EndoAns);
		cout<<"\n \n";
	}
}
void matchAbdPainAdultKidneyStones(bool arr[41]){
	 bool KSAns[41]={0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0};

	bool ks=false;
	for(int i=0; i<41; i++){
		if(arr[i]==KSAns[i]){
			ks=true;
			
		}
	}
	if(ks==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH KIDNEY STONES  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsAbdPain(arr, KSAns);
		printremainingsymptomsAbdPain(arr, KSAns);
		cout<<"\n \n";
	}
}
void matchAbdPainAdultPancreatitis(bool arr[41]){
	 bool PanAns[41]={0,0,0,0,1,0,0,1,1,1,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0};

	bool pan=false;
	for(int i=0; i<41; i++){
		if(arr[i]==PanAns[i]){
			pan=true;
			
		}
	}
	if(pan==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH PANCREATITIS  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsAbdPain(arr, PanAns);
		printremainingsymptomsAbdPain(arr, PanAns);
		cout<<"\n \n";
	}
}
void matchAbdPainAdultGallstones(bool arr[41]){
	 bool GSAns[41]={0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0};

	bool gs=false;
	for(int i=0; i<41; i++){
		if(arr[i]==GSAns[i]){
			gs=true;
			
		}
	}
	if(gs==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH GALLSTONES  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsAbdPain(arr, GSAns);
		printremainingsymptomsAbdPain(arr, GSAns);
		cout<<"\n \n";
	}
}
void printmatchingsymptomsCough(bool arr[26], bool disease[26]) {
	for (int i = 0; i < 26; i++) {
		if (arr[i] == disease[i] && arr[i] == 1) {
			switch (i) {
			case 0: cout << "cough is dry" << endl;   break;
			case 1: cout << "cough is producing sputum" << endl;   break;
			case 2: cout << "cough is producing plegm" << endl;   break;
			case 3: cout << "problem is new" << endl;   break;
			case 4: cout << "problem is recent" << endl;   break;
			case 5: cout << "problem is worsning" << endl;   break;
			case 6: cout << "problem is progressing" << endl;   break;
			case 7: cout << "problem is ongoing" << endl;   break;
			case 8: cout << "problem is recurrent" << endl;   break;
			case 9: cout << "triggered or wosened by allergens" << endl;   break;
			case 10: cout << "triggered or wosened by irritants" << endl;   break;
			case 11: cout << "accompanied by chest pain " << endl;   break;
			case 12: cout << "accompained by tightness" << endl;   break;
			case 13: cout << "accompained by chills" << endl;   break;
			case 14: cout << "accompained by difficult swelling" << endl;   break;
			case 15: cout << "accompained by painful swelling" << endl;   break;
			case 16: cout << "accompained by fatigue" << endl;   break;
			case 17: cout << "accompained by fever" << endl;   break;
			case 18: cout << "accompained by hedache" << endl;   break;
			case 19: cout << "accompained by soar throat" << endl;   break;
			case 20: cout << "accompained by sneezing" << endl;   break;
			case 21: cout << "accompained by shortness of breath" << endl;   break;
			case 22: cout << "accompained by wheezing" << endl;   break;
			case 23: cout << "accompained by appetite" << endl;   break;
			case 24: cout << "accompained by musclaches" << endl;   break;
			case 25: cout << "accompained by itchy eyes" << endl;   break;
			
			}

		}
	}

}
void printremainingsymptomsCough(bool arr[26], bool disease[26]) {

	bool remainingsymptomspresent = false;

	for (int i = 0; i < 26; i++) {
		if (arr[i] != disease[i] && disease[i] == 1) {
			remainingsymptomspresent = true;
		}
	}
	if (remainingsymptomspresent == true) {
		cout << "OTHER SYMPTOMS INCLUDE:" << endl;

		for (int i = 0; i < 26; i++) {
			if (arr[i] != disease[i] && disease[i] == 1) {
				switch (i) {
				case 0: cout << "cough is dry" << endl;   break;
				case 1: cout << "cough is producing sputum" << endl;   break;
				case 2: cout << "cough is producing plegm" << endl;   break;
				case 3: cout << "problem is new" << endl;   break;
				case 4: cout << "problem is recent" << endl;   break;
				case 5: cout << "problem is worsning" << endl;   break;
				case 6: cout << "problem is progressing" << endl;   break;
				case 7: cout << "problem is ongoing" << endl;   break;
				case 8: cout << "problem is recurrent" << endl;   break;
				case 9: cout << "triggered or wosened by allergens" << endl;   break;
				case 10: cout << "triggered or wosened by irritants" << endl;   break;
				case 11: cout << "accompanied by chest pain " << endl;   break;
				case 12: cout << "accompained by tightness" << endl;   break;
				case 13: cout << "accompained by chills" << endl;   break;
				case 14: cout << "accompained by difficult swelling" << endl;   break;
				case 15: cout << "accompained by painful swelling" << endl;   break;
				case 16: cout << "accompained by fatigue" << endl;   break;
				case 17: cout << "accompained by fever" << endl;   break;
				case 18: cout << "accompained by hedache" << endl;   break;
				case 19: cout << "accompained by soar throat" << endl;   break;
				case 20: cout << "accompained by sneezing" << endl;   break;
				case 21: cout << "accompained by shortness of breath" << endl;   break;
				case 22: cout << "accompained by wheezing" << endl;   break;
				case 23: cout << "accompained by appetite" << endl;   break;
				case 24: cout << "accompained by musclaches" << endl;   break;
				case 25: cout << "accompained by itchy eyes" << endl;   break;
				}
			}

		}
	}


}
void matchCoughinAdultsLaryngitis(bool arr[26]) {


	bool LaryngitisAns[26] = { 0,1,1,0,1,0,0,1,1,1,0,0,1,1,1,0,1,0,0,0,0,0,0,0,0,0 };

	bool Laryngitis = false;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == LaryngitisAns[i]) {
			Laryngitis = true;

		}
	}
	if (Laryngitis == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH Laryngitis  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH \n";
		printmatchingsymptomsCough(arr, LaryngitisAns);
		printremainingsymptomsCough(arr, LaryngitisAns);
		cout << "\n \n";
	}
}
void matchCoughinAdultsPneumonia(bool arr[26]) {
	bool PneumoniaAns[26] = { 0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	bool Pneumonia = false;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == PneumoniaAns[i]) {
			Pneumonia = true;

		}
	}
	if (Pneumonia == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH Pneumonia  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsCough(arr, PneumoniaAns);
		printremainingsymptomsCough(arr, PneumoniaAns);
		cout << "\n \n";
	}
}
void matchCoughinAdultsBronchitis(bool arr[26]) {
	bool BronchitisAns[26] = { 0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0 };

	bool Bronchitis = false;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == BronchitisAns[i]) {
			Bronchitis = true;

		}
	}
	if (Bronchitis == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH Bronchitis  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsCough(arr, BronchitisAns);
		printremainingsymptomsCough(arr, BronchitisAns);
		cout << "\n \n";
	}
}
void CoughinAdultsCommoncold(bool arr[26]) {
	bool CommoncoldAns[26] = { 0,1,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0 };

	bool Commoncold = false;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == CommoncoldAns[i]) {
			Commoncold = true;

		}
	}
	if (Commoncold == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH Commoncold  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsCough(arr, CommoncoldAns);
		printremainingsymptomsCough(arr, CommoncoldAns);
		cout << "\n \n";
	}
}
void matchCoughinAdultsEmphysema(bool arr[26]) {
	bool EmphysemaAns[41] = { 0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0 };

	bool Emphysema = false;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == EmphysemaAns[i]) {
			Emphysema = true;

		}
	}
	if (Emphysema == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH LACTOSE Emphysema \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsCough(arr, EmphysemaAns);
		printremainingsymptomsCough(arr, EmphysemaAns);
		cout << "\n \n";
	}
}
void matchCoughinAdultsHayfever(bool arr[26]) {
	bool HayfeverAns[26] = { 0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0 };

	bool Hayfever = false;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == HayfeverAns[i]) {
			Hayfever = true;

		}
	}
	if (Hayfever == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH FOOD Hayfever  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsCough(arr, HayfeverAns);
		printremainingsymptomsCough(arr, HayfeverAns);
		cout << "\n \n";
	}
}
void CoughinAdultsInfluenza(bool arr[26]) {
	bool InfluenzaAns[26] = { 0,1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0 };

	bool Influenza = false;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == InfluenzaAns[i]) {
			Influenza = true;

		}
	}
	if (Influenza == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH Influenza  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsCough(arr, InfluenzaAns);
		printremainingsymptomsCough(arr, InfluenzaAns);
		cout << "\n \n";
	}
}
void matchCoughinAdultsAcutesinusitis(bool arr[26]) {
	bool AcutesinusitisAns[41] = { 0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0 };

	bool Acutesinusitis = false;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == AcutesinusitisAns[i]) {
			Acutesinusitis = true;

		}
	}
	if (Acutesinusitis == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH Acutesinusitis  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsCough(arr, AcutesinusitisAns);
		printremainingsymptomsCough(arr, AcutesinusitisAns);
		cout << "\n \n";
	}
}
void matchCoughinAdultsAsthma(bool arr[26]) {
	bool AsthmaAns[26] = { 0,0,0,0,1,0,0,1,1,1,0,1,0,0,0,1,0,0,1,0,0,0,0,1,0,0 };

	bool Asthma = false;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == AsthmaAns[i]) {
			Asthma = true;

		}
	}
	if (Asthma == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH Asthma  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsCough(arr, AsthmaAns);
		printremainingsymptomsCough(arr, AsthmaAns);
		cout << "\n \n";
	}
}
void matchCoughinAdultsChronicsinusitis(bool arr[26]) {
	bool ChronicsinusitisAns[26] = { 0,0,0,0,1,1,0,0,1,0,0,1,0,1,0,1,0,0,1,0,0,0,0,0,0,0 };

	bool Chronicsinusitis = false;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == ChronicsinusitisAns[i]) {
			Chronicsinusitis = true;

		}
	}
	if (Chronicsinusitis == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH Chronicsinusitis  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsCough(arr, ChronicsinusitisAns);
		printremainingsymptomsCough(arr, ChronicsinusitisAns);
		cout << "\n \n";
	}
}
void printmatchingsymptomsST(bool arr[18], bool disease[18]) {
	for (int i = 0; i < 18; i++) {
		if (arr[i] == disease[i] && arr[i] == 1) {
			switch (i) {
			case 0: cout << "accompained by blue coloured skin or lips" << endl;   break;
			case 1: cout << "accompained by chills or sweating" << endl;   break;
			case 2: cout << "accompained by cough" << endl;   break;
			case 3: cout << "accompained by difficult or painful swallowing" << endl;   break;
			case 4: cout << "accompained by difficult or raspy breathing" << endl;   break;
			case 5: cout << "accompained by enlarged,tender lymph nodes in neck" << endl;   break;
			case 6: cout << "accompained by fever" << endl;   break;
			case 7: cout << "accompained by hedache or facial pain" << endl;   break;
			case 8: cout << "accompained by heartburn" << endl;   break;
			case 9: cout << "accompained by hoarse or muffled voice" << endl;   break;
			case 10: cout << "accompained by muscle aches" << endl;   break;
			case 11: cout << "accompained by red,swollen tonsils" << endl;   break;
			case 12: cout << "accompained by runny or stuffy nose" << endl;   break;
			case 13: cout << "accompained by skin rash" << endl;   break;
			case 14: cout << "accompained by sneezing" << endl;   break;
			case 15: cout << "accompained by watery eyes" << endl;   break;
			case 16: cout << "accompained by white patches or pus on tonsils" << endl;   break;
			case 17: cout << "accompained by yellow or greenish phlegm or discharge from nose" << endl;   break;

			}

		}
	}

}
void printremainingsymptomsST(bool arr[18], bool disease[18]) {

	bool remainingsymptomspresent = false;

	for (int i = 0; i < 18; i++) {
		if (arr[i] != disease[i] && disease[i] == 1) {
			remainingsymptomspresent = true;
		}
	}
	if (remainingsymptomspresent == true) {
		cout << "OTHER SYMPTOMS INCLUDE:" << endl;

		for (int i = 0; i < 18; i++) {
			if (arr[i] != disease[i] && disease[i] == 1) {
				switch (i) {
				case 0: cout << "accompained by blue coloured skin or lips" << endl;   break;
				case 1: cout << "accompained by chills or sweating" << endl;   break;
				case 2: cout << "accompained by cough" << endl;   break;
				case 3: cout << "accompained by difficult or painful swallowing" << endl;   break;
				case 4: cout << "accompained by difficult or raspy breathing" << endl;   break;
				case 5: cout << "accompained by enlarged,tender lymph nodes in neck" << endl;   break;
				case 6: cout << "accompained by fever" << endl;   break;
				case 7: cout << "accompained by hedache or facial pain" << endl;   break;
				case 8: cout << "accompained by heartburn" << endl;   break;
				case 9: cout << "accompained by hoarse or muffled voice" << endl;   break;
				case 10: cout << "accompained by muscle aches" << endl;   break;
				case 11: cout << "accompained byred,swollen tonsils" << endl;   break;
				case 12: cout << "accompained by runny or stuffy nose" << endl;   break;
				case 13: cout << "accompained by skin rash" << endl;   break;
				case 14: cout << "accompained by sneezing" << endl;   break;
				case 15: cout << "accompained by watery eyes" << endl;   break;
				case 16: cout << "accompained by white partches or pus on tonsils" << endl;   break;
				case 17: cout << "accompained by yellow or greenish phlegm or discharge from nose" << endl;
				}
			}

		}
	}


}
void matchTonsillitis(bool arr[18]) {


	bool TonsillitisAns[18] = { 0,0,0,1,0,1,1,1,0,1,0,1,0,1,0,0,1,0 };

	bool Tonsillitis = false;
	for (int i = 0; i < 18; i++) {
		if (arr[i] == TonsillitisAns[i]) {
			Tonsillitis = true;

		}
	}
	if (Tonsillitis == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH TONSILLITIS  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH \n";
		printmatchingsymptomsST(arr, TonsillitisAns);
		printremainingsymptomsST(arr, TonsillitisAns);
		cout << "\n \n";
	}
}
void matchCommonCold(bool arr[18]) {
	bool CommonColdAns[18] = { 0,0,1,0,0,0,0,1,0,0,1,0,1,0,1,1,0,1 };

	bool CommonCold = false;
	for (int i = 0; i < 18; i++) {
		if (arr[i] == CommonColdAns[i]) {
			CommonCold = true;

		}
	}
	if (CommonCold == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH COMMON COLD  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsST(arr, CommonColdAns);
		printremainingsymptomsST(arr, CommonColdAns);
		cout << "\n \n";
	}
}
void matchInfluenza(bool arr[18]) {
	bool InfluenzaAns[18] = { 0,1,1,0,0,0,1,1,0,0,1,0,1,0,1,0,0,0 };

	bool Influenza = false;
	for (int i = 0; i < 18; i++) {
		if (arr[i] == InfluenzaAns[i]) {
			Influenza = true;

		}
	}
	if (Influenza == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH INFLUENZA  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsST(arr, InfluenzaAns);
		printremainingsymptomsST(arr, InfluenzaAns);
		cout << "\n \n";
	}
}
void matchStrepThroat(bool arr[18]) {
	bool StrepThroatAns[18] = { 0,0,0,1,0,1,1,1,0,0,0,1,0,1,0,0,1,0 };

	bool StrepThroat = false;
	for (int i = 0; i < 18; i++) {
		if (arr[i] == StrepThroatAns[i]) {
			StrepThroat = true;

		}
	}
	if (StrepThroat == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH STREP THROAT  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsST(arr, StrepThroatAns);
		printremainingsymptomsST(arr, StrepThroatAns);
		cout << "\n \n";
	}
}
void matchMononucleasis(bool arr[18]) {
	bool MononucleasisAns[18] = { 0,1,0,0,0,1,1,1,0,0,0,1,0,1,0,0,0,0 };

	bool Mononucleasis = false;
	for (int i = 0; i < 18; i++) {
		if (arr[i] == MononucleasisAns[i]) {
			Mononucleasis = true;

		}
	}
	if (Mononucleasis == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH MONONUCLEASIS \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsST(arr, MononucleasisAns);
		printremainingsymptomsST(arr, MononucleasisAns);
		cout << "\n \n";
	}
}
void matchEpiglottitis(bool arr[18]) {
	bool EpiglottitisAns[18] = { 1,0,0,1,1,0,1,0,0,1,0,0,0,0,0,0,0,0 };

	bool Epiglottitis = false;
	for (int i = 0; i < 18; i++) {
		if (arr[i] == EpiglottitisAns[i]) {
			Epiglottitis = true;

		}
	}
	if (Epiglottitis == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH EPIGLOTTITIS  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsST(arr, EpiglottitisAns);
		printremainingsymptomsST(arr, EpiglottitisAns);
		cout << "\n \n";
	}
}
void matchHayfever(bool arr[18]) {
	bool HayfeverAns[18] = { 0,0,1,0,0,0,0,1,0,0,0,0,1,0,1,1,0,0 };

	bool Hayfever = false;
	for (int i = 0; i < 18; i++) {
		if (arr[i] == HayfeverAns[i]) {
			Hayfever = true;

		}
	}
	if (Hayfever == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH HAY FEVER  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsST(arr, HayfeverAns);
		printremainingsymptomsST(arr, HayfeverAns);
		cout << "\n \n";
	}
}
void matchAcuteSinusitis(bool arr[18]) {
	bool AcuteSinusitisAns[18] = { 0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1 };

	bool AcuteSinusitis = false;
	for (int i = 0; i < 18; i++) {
		if (arr[i] == AcuteSinusitisAns[i]) {
			AcuteSinusitis = true;

		}
	}
	if (AcuteSinusitis == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH ACUTE SINUSITIS  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsST(arr, AcuteSinusitisAns);
		printremainingsymptomsST(arr, AcuteSinusitisAns);
		cout << "\n \n";
	}
}
void matchGastroesophagealrefluxdisease(bool arr[18]) {
	bool GastroesophagealrefluxdiseaseAns[18] = { 0,0,1,1,0,0,0,0,1,1,0,0,0,0,0,0,0,0 };

	bool Gastroesophagealrefluxdisease = false;
	for (int i = 0; i < 18; i++) {
		if (arr[i] == GastroesophagealrefluxdiseaseAns[i]) {
			Gastroesophagealrefluxdisease = true;

		}
	}
	if (Gastroesophagealrefluxdisease == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH GASTROESOPHAGEAL REFLUX DISEASE  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsST(arr, GastroesophagealrefluxdiseaseAns);
		printremainingsymptomsST(arr, GastroesophagealrefluxdiseaseAns);
		cout << "\n \n";
	}
}
void matchLaryngitis(bool arr[18]) {
	bool LaryngitisAns[18] = { 0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0 };

	bool Laryngitis = false;
	for (int i = 0; i < 18; i++) {
		if (arr[i] == LaryngitisAns[i]) {
			Laryngitis = true;

		}
	}
	if (Laryngitis == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH LARYNGITIS  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsST(arr, LaryngitisAns);
		printremainingsymptomsST(arr, LaryngitisAns);
		cout << "\n \n";
	}
}
void printmatchingsymptomsDZ(bool arr[20], bool disease[20]){
	for(int i=0; i<20; i++){
		if(arr[i]==disease[i] && arr[i]==1){
			switch (i) {
				case 0: cout<<"You feel a spinning sensation"<<endl;   break;
				case 1: cout<<"You feel unsteady"<<endl;   break;
				case 2: cout<<"You feel lightheaded or faint"<<endl;   break;
				case 3: cout<<"Symptoms are new or sudden"<<endl;   break;
				case 4: cout<<"Symptoms are ongoing or recurrent"<<endl;   break;
				case 5: cout<<"Triggered or worsened by change in head or body position"<<endl;   break;
				case 6: cout<<"Accompanied by anxiety"<<endl;   break;
				case 7: cout<<"Accompanied by nausea or vomiting"<<endl;   break;
				case 8: cout<<"Accompanied by blurred or double vision"<<endl;   break;
				case 9: cout<<"Accompanied by numbness or weakness"<<endl;   break;
				case 10: cout<<"Accompanied by buzzing or ringing in ear"<<endl;   break;
				case 11: cout<<"Accompanied by pain in neck,jaw,arms etc"<<endl;   break;
				case 12: cout<<"Accompanied by buzzing or ringing in only one ear"<<endl;   break;
				case 13: cout<<"Accompanied by rapid or irrapid heartbeat"<<endl;   break;
				case 14: cout<<"Accompanied by chest pain"<<endl;   break;
				case 15: cout<<"Accompanied by severe headache"<<endl;   break;
				case 16: cout<<"Accompanied by confusion"<<endl;   break;
				case 17: cout<<"Accompanied by shortness of breath"<<endl;   break;
				case 18: cout<<"Accompanied by ear pain"<<endl;   break;
				case 19: cout<<"Accompanied by slurred speech"<<endl;   break;
				
			}
			
		}
	}
	
}
void printremainingsymptomsDZ(bool arr[20], bool disease[20]){
	
	bool remainingsymptomspresent=false;
	
	for(int i=0; i<20; i++){
		if(arr[i]!=disease[i] && disease[i]==1){
			remainingsymptomspresent=true;
		}
	}
	if(remainingsymptomspresent==true){
		cout<<"OTHER SYMPTOMS INCLUDE:"<<endl;
	
	for(int i =0; i<20; i++){
		if(arr[i]!=disease[i] && disease[i]==1){
			switch (i) {
				case 0: cout<<"You feel a spinning sensation"<<endl;   break;
				case 1: cout<<"You feel unsteady"<<endl;   break;
				case 2: cout<<"You feel lightheaded or faint"<<endl;   break;
				case 3: cout<<"Symptoms are new or sudden"<<endl;   break;
				case 4: cout<<"Symptoms are ongoing or recurrent"<<endl;   break;
				case 5: cout<<"Triggered or worsened by change in head or body position"<<endl;   break;
				case 6: cout<<"Accompanied by anxiety"<<endl;   break;
				case 7: cout<<"Accompanied by nausea or vomiting"<<endl;   break;
				case 8: cout<<"Accompanied by blurred or double vision"<<endl;   break;
				case 9: cout<<"Accompanied by numbness or weakness"<<endl;   break;
				case 10: cout<<"Accompanied by buzzing or ringing in ear"<<endl;   break;
				case 11: cout<<"Accompanied by pain in neck,jaw,arms etc"<<endl;   break;
				case 12: cout<<"Accompanied by buzzing or ringing in only one ear"<<endl;   break;
				case 13: cout<<"Accompanied by rapid or irrapid heartbeat"<<endl;   break;
				case 14: cout<<"Accompanied by chest pain"<<endl;   break;
				case 15: cout<<"Accompanied by severe headache"<<endl;   break;
				case 16: cout<<"Accompanied by confusion"<<endl;   break;
				case 17: cout<<"Accompanied by shortness of breath"<<endl;   break;
				case 18: cout<<"Accompanied by ear pain"<<endl;   break;
				case 19: cout<<"Accompanied by slurred speech"<<endl;   break;
				
			}
		}
		
	}
}
	
	
}
void matchStroke(bool arr[20]){
	
	
    bool StrokeAns[20]={1,1,1,1,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,1};

	bool Stroke=false;
	for(int i=0; i<20; i++){
		if(arr[i]==StrokeAns[i]){
			Stroke=true;
			
		}
	}
	if(Stroke==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Stroke  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH \n";
		printmatchingsymptomsDZ(arr, StrokeAns);
		printremainingsymptomsDZ(arr, StrokeAns);
		cout<<"\n \n";
	}
}
void matchHeartattack(bool arr[20]){
	 bool HeartattackAns[20]={0,0,1,1,0,0,1,1,0,0,0,1,0,1,1,0,0,1,0,0};
	 
	bool Heartattack=false;
	for(int i=0; i<20; i++){
		if(arr[i]==HeartattackAns[i]){
			Heartattack=true;
			
		}
	}
	if(Heartattack==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Heart Attack  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsDZ(arr, HeartattackAns);
		printremainingsymptomsDZ(arr, HeartattackAns);
		cout<<"\n \n";
	}
}
void matchMigraine(bool arr[20]){
	 bool MigraineAns[20]={1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0};

	bool Migraine=false;
	for(int i=0; i<20; i++){
		if(arr[i]==MigraineAns[i]){
			Migraine=true;
			
		}
	}
	if(Migraine==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Migraine  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsDZ(arr, MigraineAns);
		printremainingsymptomsDZ(arr, MigraineAns);
		cout<<"\n \n";
	}
}
void matchEarinfection(bool arr[20]){
	 bool EarinfectionAns[20]={1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0};

	bool Earinfection=false;
	for(int i=0; i<20; i++){
		if(arr[i]==EarinfectionAns[i]){
			Earinfection=true;
			
		}
	}
	if(Earinfection==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Ear infection \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsDZ(arr, EarinfectionAns);
		printremainingsymptomsDZ(arr, EarinfectionAns);
		cout<<"\n \n";
	}
}
void matchCarbonmonoxidepoisoning(bool arr[20]){
	 bool CarbonmonoxidepoisoningAns[20]={0,0,1,1,0,0,0,1,0,0,0,0,0,0,1,1,1,0,0,0};

	bool Carbonmonoxidepoisoning=false;
	for(int i=0; i<20; i++){
		if(arr[i]==CarbonmonoxidepoisoningAns[i]){
			Carbonmonoxidepoisoning=true;
			
		}
	}
	if(Carbonmonoxidepoisoning==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Carbonmonoxidepoisoning \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsDZ(arr, CarbonmonoxidepoisoningAns);
		printremainingsymptomsDZ(arr, CarbonmonoxidepoisoningAns);
		cout<<"\n \n";
	}
}
void matchAcousticneuroma(bool arr[20]){
	 bool AcousticneuromaAns[20]={1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0};

	bool Acousticneuroma=false;
	for(int i=0; i<20; i++){
		if(arr[i]==AcousticneuromaAns[i]){
			Acousticneuroma=true;
			
		}
	}
	if(Acousticneuroma==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Acoustic neuroma  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsDZ(arr, AcousticneuromaAns);
		printremainingsymptomsDZ(arr, AcousticneuromaAns);
		cout<<"\n \n";
	}
}
void printmatchingsymptomsDS(bool arr[20], bool disease[20]) {
	for (int i = 0; i < 20; i++) {
		if (arr[i] == disease[i] && arr[i] == 1) {
			switch (i) {
			case 0: cout << "swallowing hurts" << endl;   break;
			case 1: cout << "swallowing takes effort" << endl;   break;
			case 2: cout << "trigerred or worsened by eating certain foods" << endl;   break;
			case 3: cout << "accompained by bad breath" << endl;   break;
			case 4: cout << "accompained by cough" << endl;   break;
			case 5: cout << "accompained by difficult breathing" << endl;   break;
			case 6: cout << "accompained by dry mouth" << endl;   break;
			case 7: cout << "accompained by earache" << endl;   break;
			case 8: cout << "accompained by feeling of something stuck in your throat " << endl;   break;
			case 9: cout << "accompained by heartburn" << endl;   break;
			case 10: cout << "accompained by hoarse voice or difficulty speaking" << endl;   break;
			case 11: cout << "accompained byjaw pain or stifness" << endl;   break;
			case 12: cout << "accompained by loose teeth or poorly fitting dentures" << endl;   break;
			case 13: cout << "accompained by lump in front of neck" << endl;   break;
			case 14: cout << "accompained by mouth sores,lumps or pain" << endl;   break;
			case 15: cout << "accompained by pain in chest or back" << endl;   break;
			case 16: cout << "accompained by regurgitation of food or sour liquid" << endl;   break;
			case 17: cout << "accompained by sore throat" << endl;   break;
			case 18: cout << "accompained by thick saliva" << endl;   break;
			case 19: cout << "accompained by uninteded weight loss" << endl;   break;

			}

		}
	}

}
void printremainingsymptomsDS(bool arr[20], bool disease[20]) {

	bool remainingsymptomspresent = false;

	for (int i = 0; i < 20; i++) {
		if (arr[i] != disease[i] && disease[i] == 1) {
			remainingsymptomspresent = true;
		}
	}
	if (remainingsymptomspresent == true) {
		cout << "OTHER SYMPTOMS INCLUDE:" << endl;

		for (int i = 0; i < 20; i++) {
			if (arr[i] != disease[i] && disease[i] == 1) {
				switch (i) {
				case 0: cout << "swallowing hurts" << endl;   break;
				case 1: cout << "swallowing takes effort" << endl;   break;
				case 2: cout << "trigerred or worsened by eating certain foods" << endl;   break;
				case 3: cout << "accompained by bad breath" << endl;   break;
				case 4: cout << "accompained by cough" << endl;   break;
				case 5: cout << "accompained by difficult breathing" << endl;   break;
				case 6: cout << "accompained by dry mouth" << endl;   break;
				case 7: cout << "accompained by earache" << endl;   break;
				case 8: cout << "accompained by feeling of something stuck in your throat " << endl;   break;
				case 9: cout << "accompained by heartburn" << endl;   break;
				case 10: cout << "accompained by hoarse voice or difficulty speaking" << endl;   break;
				case 11: cout << "accompained byjaw pain or stifness" << endl;   break;
				case 12: cout << "accompained by loose teeth or poorly fitting dentures" << endl;   break;
				case 13: cout << "accompained by lump in front of neck" << endl;   break;
				case 14: cout << "accompained by mouth sores,lumps or pain" << endl;   break;
				case 15: cout << "accompained by pain in chest or back" << endl;   break;
				case 16: cout << "accompained by regurgitation of food or sour liquid" << endl;   break;
				case 17: cout << "accompained by sore throat" << endl;   break;
				case 18: cout << "accompained by thick saliva" << endl;   break;
				case 19: cout << "accompained by uninteded weight loss" << endl;   break;
				}
			}

		}
	}


}
void matchGastroesophagealrefluxdisease2(bool arr[20]) {


	bool GastroesophagealrefluxdiseaseAns[20] = { 0,1,1,0,1,0,0,0,1,1,1,0,0,0,0,1,1,1,0,0 };

	bool Gastroesophagealrefluxdisease = false;
	for (int i = 0; i < 20; i++) {
		if (arr[i] == GastroesophagealrefluxdiseaseAns[i]) {
			Gastroesophagealrefluxdisease = true;

		}
	}
	if (Gastroesophagealrefluxdisease == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH GASTROESOPHAGEAL REFLUX DISEASE  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH \n";
		printmatchingsymptomsDS(arr, GastroesophagealrefluxdiseaseAns);
		printremainingsymptomsDS(arr, GastroesophagealrefluxdiseaseAns);
		cout << "\n \n";
	}
}
void matchThroatcancer(bool arr[20]) {
	bool ThroatcancerAns[20] = { 0,1,0,1,1,1,0,1,1,0,0,0,0,1,0,0,0,1,0,1 };

	bool Throatcancer = false;
	for (int i = 0; i < 20; i++) {
		if (arr[i] == ThroatcancerAns[i]) {
			Throatcancer = true;

		}
	}
	if (Throatcancer == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH THROAT DISEASE  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsDS(arr, ThroatcancerAns);
		printremainingsymptomsDS(arr, ThroatcancerAns);
		cout << "\n \n";
	}
}
void matchEsophagealcancer(bool arr[20]) {
	bool EsophagealcancerAns[20] = { 1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,0,0,1 };

	bool Esophagealcancer = false;
	for (int i = 0; i < 20; i++) {
		if (arr[i] == EsophagealcancerAns[i]) {
			Esophagealcancer = true;

		}
	}
	if (Esophagealcancer == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH ESOPHAGEAL CANCER  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsDS(arr, EsophagealcancerAns);
		printremainingsymptomsDS(arr, EsophagealcancerAns);
		cout << "\n \n";
	}
}
void matchMouthcancer(bool arr[20]) {
	bool MouthcancerAns[20] = { 1,1,0,0,0,0,0,0,1,0,0,1,1,0,1,0,0,1,0,0 };

	bool Mouthcancer = false;
	for (int i = 0; i < 20; i++) {
		if (arr[i] == MouthcancerAns[i]) {
			Mouthcancer = true;

		}
	}
	if (Mouthcancer == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH MOUTH CANCER  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsDS(arr, MouthcancerAns);
		printremainingsymptomsDS(arr, MouthcancerAns);
		cout << "\n \n";
	}
}
void matchEsophagealspasms(bool arr[20]) {
	bool EsophagealspasmsAns[20] = { 0,1,0,0,0,0,0,0,1,1,0,0,0,0,0,1,1,0,0,0 };

	bool Esophagealspasms = false;
	for (int i = 0; i < 20; i++) {
		if (arr[i] == EsophagealspasmsAns[i]) {
			Esophagealspasms = true;

		}
	}
	if (Esophagealspasms == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH ESOPHAGEAL SPASMS \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsDS(arr, EsophagealspasmsAns);
		printremainingsymptomsDS(arr, EsophagealspasmsAns);
		cout << "\n \n";
	}
}
void matchDrymouth(bool arr[20]) {
	bool DrymouthAns[20] = { 0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0 };

	bool Drymouth = false;
	for (int i = 0; i < 20; i++) {
		if (arr[i] == DrymouthAns[i]) {
			Drymouth = true;

		}
	}
	if (Drymouth == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH DRY MOUTH  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsDS(arr, DrymouthAns);
		printremainingsymptomsDS(arr, DrymouthAns);
		cout << "\n \n";
	}
}
void printmatchingsymptomsWA(bool arr[17], bool disease[17]) {
	for (int i = 0; i < 17; i++) {
		if (arr[i] == disease[i] && arr[i] == 1) {
			switch (i) {
			case 0: cout << "wheezing is new or recent" << endl;   break;
			case 1: cout << "wheezing is ongoing or recurrent" << endl;   break;
			case 2: cout << "preceeded by upper respiratory illness" << endl;   break;
			case 3: cout << "triggered or worsened by allergens or irritants" << endl;   break;
			case 4: cout << "triggered or worsened by exposure to cold air" << endl;   break;
			case 5: cout << "triggered or worsened by mild to moderate exertion" << endl;   break;
			case 6: cout << "triggered or worsened by smoking" << endl;   break;
			case 7: cout << "accompanied by blue coloured-skin or lips " << endl;   break;
			case 8: cout << "accompanied by chest pain or tightness" << endl;   break;
			case 9: cout << "accompanied by cough that produces sputum" << endl;   break;
			case 10: cout << "accompanied by difficult or painful swallowing" << endl;   break;
			case 11: cout << "accompanied by dry cough" << endl;   break;
			case 12: cout << "accompanied by fatigue or weekness" << endl;   break;
			case 13: cout << "accompanied by fever" << endl;   break;
			case 14: cout << "accompanied by hoarse or muffled voice" << endl;   break;
			case 15: cout << "accompanied by shortness of breath" << endl;   break;
			case 16: cout << "accompanied sore throat" << endl;   break;

			}

		}
	}

}
void printremainingsymptomsWA(bool arr[17], bool disease[17]) {

	bool remainingsymptomspresent = false;

	for (int i = 0; i < 17; i++) {
		if (arr[i] != disease[i] && disease[i] == 1) {
			remainingsymptomspresent = true;
		}
	}
	if (remainingsymptomspresent == true) {
		cout << "OTHER SYMPTOMS INCLUDE:" << endl;

		for (int i = 0; i < 17; i++) {
			if (arr[i] != disease[i] && disease[i] == 1) {
				switch (i) {
				case 0: cout << "wheezing is new or recent" << endl;   break;
				case 1: cout << "wheezing is ongoing or recurrent" << endl;   break;
				case 2: cout << "preceeded by upper respiratory illness" << endl;   break;
				case 3: cout << "triggered or worsened by allergens or irritants" << endl;   break;
				case 4: cout << "triggered or worsened by exposure to cold air" << endl;   break;
				case 5: cout << "triggered or worsened by mild to moderate exertion" << endl;   break;
				case 6: cout << "triggered or worsened by smoking" << endl;   break;
				case 7: cout << "accompanied by blue coloured-skin or lips " << endl;   break;
				case 8: cout << "accompanied by chest pain or tightness" << endl;   break;
				case 9: cout << "accompanied by cough that produces sputum" << endl;   break;
				case 10: cout << "accompanied by difficult or painful swallowing" << endl;   break;
				case 11: cout << "accompanied by dry cough" << endl;   break;
				case 12: cout << "accompanied by fatigue or weekness" << endl;   break;
				case 13: cout << "accompanied by fever" << endl;   break;
				case 14: cout << "accompanied by hoarse or muffled voice" << endl;   break;
				case 15: cout << "accompanied by shortness of breath" << endl;   break;
				case 16: cout << "accompanied sore throat" << endl;   break;
				}
			}

		}
	}


}
void matchAsthma(bool arr[17]) {


	bool AsthmaAns[17] = { 1,1,1,1,1,1,1,0,1,0,0,1,0,0,0,1,0 };

	bool Asthma = false;
	for (int i = 0; i < 17; i++) {
		if (arr[i] == AsthmaAns[i]) {
			Asthma = true;

		}
	}
	if (Asthma == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH ASTHMA  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH \n";
		printmatchingsymptomsWA(arr, AsthmaAns);
		printremainingsymptomsWA(arr, AsthmaAns);
		cout << "\n \n";
	}
}
void matchbronchitis(bool arr[17]) {
	bool bronchitisAns[17] = { 1,1,1,0,0,1,1,0,1,1,0,0,1,1,0,1,0 };

	bool bronchitis = false;
	for (int i = 0; i < 17; i++) {
		if (arr[i] == bronchitisAns[i]) {
			bronchitis = true;

		}
	}
	if (bronchitis == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH BRONCHITIS  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsWA(arr, bronchitisAns);
		printremainingsymptomsWA(arr, bronchitisAns);
		cout << "\n \n";
	}
}
void matchEmphysema(bool arr[17]) {
	bool EmphysemaAns[17] = { 0,0,0,0,0,1,1,0,1,0,0,1,1,0,0,1,0 };

	bool Emphysema = false;
	for (int i = 0; i < 17; i++) {
		if (arr[i] == EmphysemaAns[i]) {
			Emphysema = true;

		}
	}
	if (Emphysema == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH EMPHYSEMA  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsWA(arr, EmphysemaAns);
		printremainingsymptomsWA(arr, EmphysemaAns);
		cout << "\n \n";
	}
}
void matchEpiglottis(bool arr[17]) {
	bool EpiglottisAns[17] = { 1,0,0,0,0,0,0,1,0,0,1,0,0,1,1,0,1 };

	bool Epiglottis = false;
	for (int i = 0; i < 17; i++) {
		if (arr[i] == EpiglottisAns[i]) {
			Epiglottis = true;

		}
	}
	if (Epiglottis == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH EPIGLOTTIS  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsWA(arr, EpiglottisAns);
		printremainingsymptomsWA(arr, EpiglottisAns);
		cout << "\n \n";
	}
}
void printmatchingsymptomsWC(bool arr[20], bool disease[20]){
	for(int i=0; i<20; i++){
		if(arr[i]==disease[i] && arr[i]==1){
			switch (i) {
				case 0: cout<<"Wheezing is new or recent"<<endl;   break;
				case 1: cout<<"Wheezing is ongoing or recurrent"<<endl;   break;
				case 2: cout<<"Triggered or worsened by allergens or irritants"<<endl;   break;
				case 3: cout<<"Triggered or worsened by mild to moderate exertion"<<endl;   break;
				case 4: cout<<"Triggered or worsened by exposure to cold air"<<endl;   break;
				case 5: cout<<"Related cough is dry"<<endl;   break;
				case 6: cout<<"Related cough produces phlegm or sputum"<<endl;   break;
				case 7: cout<<"Related cough gasping , harsh or barking"<<endl;   break;
				case 8: cout<<"Accompanied by bluish skin on face"<<endl;   break;
				case 9: cout<<"Accompanied by mild body aches"<<endl;   break;
				case 10: cout<<"Accompanied by chest pain"<<endl;   break;
				case 11: cout<<"Accompanied by rapid heartbeat"<<endl;   break;
				case 12: cout<<"Accompanied by delayed growth"<<endl;   break;
				case 13: cout<<"Accompanied by rapid or difficult breathing"<<endl;   break;
				case 14: cout<<"Accompanied by drooling"<<endl;   break;
				case 15: cout<<"Accompanied by severe respiratory infections"<<endl;   break;
				case 16: cout<<"Accompanied by enlargement of fingertips"<<endl;   break;
				case 17: cout<<"Accompanied by runny nose"<<endl;   break;
				case 18: cout<<"Accompanied by failure to thrive"<<endl;   break;
				case 19: cout<<"Accompanied by shortness of breath"<<endl;   break;
				
			}
			
		}
	}
	
}
void printremainingsymptomsWC(bool arr[20], bool disease[20]){
	
	bool remainingsymptomspresent=false;
	
	for(int i=0; i<20; i++){
		if(arr[i]!=disease[i] && disease[i]==1){
			remainingsymptomspresent=true;
		}
	}
	if(remainingsymptomspresent==true){
		cout<<"OTHER SYMPTOMS INCLUDE:"<<endl;
	
	for(int i =0; i<20; i++){
		if(arr[i]!=disease[i] && disease[i]==1){
			switch (i) {
				case 0: cout<<"Wheezing is new or recent"<<endl;   break;
				case 1: cout<<"Wheezing is ongoing or recurrent"<<endl;   break;
				case 2: cout<<"Triggered or worsened by allergens or irritants"<<endl;   break;
				case 3: cout<<"Triggered or worsened by mild to moderate exertion"<<endl;   break;
				case 4: cout<<"Triggered or worsened by exposure to cold air"<<endl;   break;
				case 5: cout<<"Related cough is dry"<<endl;   break;
				case 6: cout<<"Related cough produces phlegm or sputum"<<endl;   break;
				case 7: cout<<"Related cough gasping , harsh or barking"<<endl;   break;
				case 8: cout<<"Accompanied by bluish skin on face"<<endl;   break;
				case 9: cout<<"Accompanied by mild body aches"<<endl;   break;
				case 10: cout<<"Accompanied by chest pain"<<endl;   break;
				case 11: cout<<"Accompanied by rapid heartbeat"<<endl;   break;
				case 12: cout<<"Accompanied by delayed growth"<<endl;   break;
				case 13: cout<<"Accompanied by rapid or difficult breathing"<<endl;   break;
				case 14: cout<<"Accompanied by drooling"<<endl;   break;
				case 15: cout<<"Accompanied by severe respiratory infections"<<endl;   break;
				case 16: cout<<"Accompanied by enlargement of fingertips"<<endl;   break;
				case 17: cout<<"Accompanied by runny nose"<<endl;   break;
				case 18: cout<<"Accompanied by failure to thrive"<<endl;   break;
				case 19: cout<<"Accompanied by shortness of breath"<<endl;   break;
				
			}
		}
		
	}
}
	
	
}
void matchAsthma1(bool arr[20]){
	
	
    bool AsthmaAns[20]={1,1,1,1,1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,1};

	bool Asthma=false;
	for(int i=0; i<20; i++){
		if(arr[i]==AsthmaAns[i]){
			Asthma=true;
			
		}
	}
	if(Asthma==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Asthma  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH \n";
		printmatchingsymptomsWC(arr, AsthmaAns);
		printremainingsymptomsWC(arr, AsthmaAns);
		cout<<"\n \n";
	}
}
void matchBronchiolitis(bool arr[20]){
	 bool BronchiolitisAns[20]={1,0,0,0,0,1,1,0,0,0,0,1,0,1,0,0,0,1,0,0};

	bool Bronchiolitis=false;
	for(int i=0; i<20; i++){
		if(arr[i]==BronchiolitisAns[i]){
			Bronchiolitis=true;
			
		}
	}
	if(Bronchiolitis==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Bronchiolitis  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsWC(arr, BronchiolitisAns);
		printremainingsymptomsWC(arr, BronchiolitisAns);
		cout<<"\n \n";
	}
}
void matchHayfever1(bool arr[20]){
	 bool HayfeverAns[20]={1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0};

	bool Hayfever=false;
	for(int i=0; i<20; i++){
		if(arr[i]==HayfeverAns[i]){
			Hayfever=true;
			
		}
	}
	if(Hayfever==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Hayfever  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsWC(arr, HayfeverAns);
		printremainingsymptomsWC(arr, HayfeverAns);
		cout<<"\n \n";
	}
}
void matchCroup(bool arr[20]){
	 bool CroupAns[20]={1,0,0,0,0,0,0,1,1,0,0,0,0,1,1,0,0,1,0,0};

	bool Croup=false;
	for(int i=0; i<20; i++){
		if(arr[i]==CroupAns[i]){
			Croup=true;
			
		}
	}
	if(Croup==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Croup \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsWC(arr, CroupAns);
		printremainingsymptomsWC(arr, CroupAns);
		cout<<"\n \n";
	}
}
void matchCysticfibrosis(bool arr[20]){
	 bool CysticfibrosisAns[20]={0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,1,0,1,0};

	bool Cysticfibrosis=false;
	for(int i=0; i<20; i++){
		if(arr[i]==CysticfibrosisAns[i]){
			Cysticfibrosis=true;
			
		}
	}
	if(Cysticfibrosis==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Cysticfibrosis \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsWC(arr, CysticfibrosisAns);
		printremainingsymptomsWC(arr, CysticfibrosisAns);
		cout<<"\n \n";
	}
}
void matchBronchitis(bool arr[20]){
	 bool BronchitisAns[20]={1,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,0,1};

	bool Bronchitis=false;
	for(int i=0; i<20; i++){
		if(arr[i]==BronchitisAns[i]){
			Bronchitis=true;
			
		}
	}
	if(Bronchitis==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Bronchitis  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsWC(arr, BronchitisAns);
		printremainingsymptomsWC(arr, BronchitisAns);
		cout<<"\n \n";
	}
}
void matchCommoncold(bool arr[20]){
	 bool CommoncoldAns[20]={1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,1,0,0};

	bool Commoncold=false;
	for(int i=0; i<20; i++){
		if(arr[i]==CommoncoldAns[i]){
			Commoncold=true;
			
		}
	}
	if(Commoncold==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Commoncold  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsWC(arr, CommoncoldAns);
		printremainingsymptomsWC(arr, CommoncoldAns);
		cout<<"\n \n";
	}
}
void printmatchingsymptomsFC(bool arr[14], bool disease[14]) {
	for (int i = 0; i < 14; i++) {
		if (arr[i] == disease[i] && arr[i] == 1) {
			switch (i) {
			case 0: cout << "Accompanied by abdominal pain or cramping" << endl;   break;
			case 1: cout << "Accompanied by night sweats" << endl;   break;
			case 2: cout << "Accompanied by bloody urine" << endl;   break;
			case 3: cout << "Accompanied by rapid heartbeat" << endl;   break;
			case 4: cout << "Accompanied by bloody stools" << endl;   break;
			case 5: cout << "Accompanied by Rapid or difficult breathing" << endl;   break;
			case 6: cout << "Accompanied by chest pain" << endl;   break;
			case 7: cout << "Accompanied by rash" << endl;   break;
			case 8: cout << "Accompanied by chills" << endl;   break;
			case 9: cout << "Accompanied by red spots at back of mouth" << endl;   break;
			case 10: cout << "Accompanied by cough" << endl;   break;
			case 11: cout << "Accompanied by red swollen tonsils" << endl;   break;
			case 12: cout << "Accompanied by decreased energy" << endl;   break;
			case 13: cout << "Accompanied by runny or stuffy nose" << endl;   break;


			}

		}
	}

}
void printremainingsymptomsFC(bool arr[14], bool disease[14]) {

	bool remainingsymptomspresent = false;

	for (int i = 0; i < 14; i++) {
		if (arr[i] != disease[i] && disease[i] == 1) {
			remainingsymptomspresent = true;
		}
	}
	if (remainingsymptomspresent == true) {
		cout << "OTHER SYMPTOMS INCLUDE:" << endl;

		for (int i = 0; i < 14; i++) {
			if (arr[i] != disease[i] && disease[i] == 1) {
				switch (i) {
				case 0: cout << "Accompanied by abdominal pain or cramping" << endl;   break;
				case 1: cout << "Accompanied by night sweats" << endl;   break;
				case 2: cout << "Accompanied by bloody urine" << endl;   break;
				case 3: cout << "Accompanied by rapid heartbeat" << endl;   break;
				case 4: cout << "Accompanied by bloody stools" << endl;   break;
				case 5: cout << "Accompanied by Rapid or difficult breathing" << endl;   break;
				case 6: cout << "Accompanied by chest pain" << endl;   break;
				case 7: cout << "Accompanied by rash" << endl;   break;
				case 8: cout << "Accompanied by chills" << endl;   break;
				case 9: cout << "Accompanied by red spots at back of mouth" << endl;   break;
				case 10: cout << "Accompanied by cough" << endl;   break;
				case 11: cout << "Accompanied by red swollen tonsils" << endl;   break;
				case 12: cout << "Accompanied by decreased energy" << endl;   break;
				case 13: cout << "Accompanied by runny or stuffy nose" << endl;   break;

				}
			}

		}
	}


}
void matchPneumonia(bool arr[14]) {


	bool PneumoniaAns[14] = { 0,0,0,0,0,0,1,0,1,0,1,0,1,0 };

	bool Pneumonia = false;
	for (int i = 0; i < 14; i++) {
		if (arr[i] == PneumoniaAns[i]) {
			Pneumonia = true;

		}
	}
	if (Pneumonia == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH Pneumonia  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH \n";
		printmatchingsymptomsFC(arr, PneumoniaAns);
		printremainingsymptomsFC(arr, PneumoniaAns);
		cout << "\n \n";
	}
}
void matchBronchiolitis1(bool arr[14]) {
	bool BronchiolitisAns[14] = { 0,0,0,0,0,0,0,0,0,0,1,0,0,1 };

	bool Bronchiolitis = false;
	for (int i = 0; i < 14; i++) {
		if (arr[i] == BronchiolitisAns[i]) {
			Bronchiolitis = true;

		}
	}
	if (Bronchiolitis == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH Bronchiolitis  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsFC(arr, BronchiolitisAns);
		printremainingsymptomsFC(arr, BronchiolitisAns);
		cout << "\n \n";
	}
}
void matchMononucleosis(bool arr[14]) {
	bool MononucleosisAns[14] = { 0,1,0,0,0,0,0,1,0,0,0,1,1,0 };

	bool Mononucleosis = false;
	for (int i = 0; i < 14; i++) {
		if (arr[i] == MononucleosisAns[i]) {
			Mononucleosis = true;

		}
	}
	if (Mononucleosis == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH Mononucleosis  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsFC(arr, MononucleosisAns);
		printremainingsymptomsFC(arr, MononucleosisAns);
		cout << "\n \n";
	}
}
void matchInfluenza1(bool arr[14]) {
	bool InfluenzaAns[14] = { 0,0,0,0,0,0,0,0,1,0,0,0,1,1 };

	bool Influenza = false;
	for (int i = 0; i < 14; i++) {
		if (arr[i] == InfluenzaAns[i]) {
			Influenza = true;

		}
	}
	if (Influenza == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH Influenza \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsFC(arr, InfluenzaAns);
		printremainingsymptomsFC(arr, InfluenzaAns);
		cout << "\n \n";
	}
}
void matchRoseola(bool arr[14]) {
	bool RoseolaAns[14] = { 0,0,0,0,0,0,0,1,0,0,0,0,1,0 };

	bool Roseola = false;
	for (int i = 0; i < 14; i++) {
		if (arr[i] == RoseolaAns[i]) {
			Roseola = true;

		}
	}
	if (Roseola == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH Roseola \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsFC(arr, RoseolaAns);
		printremainingsymptomsFC(arr, RoseolaAns);
		cout << "\n \n";
	}
}
void matchRotavirus(bool arr[14]) {
	bool RotavirusAns[14] = { 0,0,0,0,1,0,0,0,0,0,0,0,1,0 };

	bool Rotavirus = false;
	for (int i = 0; i < 14; i++) {
		if (arr[i] == RotavirusAns[i]) {
			Rotavirus = true;

		}
	}
	if (Rotavirus == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH Rotavirus  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsFC(arr, RotavirusAns);
		printremainingsymptomsFC(arr, RotavirusAns);
		cout << "\n \n";
	}
}
void matchCommoncold1(bool arr[14]) {
	bool CommoncoldAns[14] = { 0,0,0,0,0,0,0,0,0,0,1,0,1,1 };

	bool Commoncold = false;
	for (int i = 0; i < 14; i++) {
		if (arr[i] == CommoncoldAns[i]) {
			Commoncold = true;

		}
	}
	if (Commoncold == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH Common cold  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsFC(arr, CommoncoldAns);
		printremainingsymptomsFC(arr, CommoncoldAns);
		cout << "\n \n";
	}
}
void printmatchingsymptomsDC(bool arr[20], bool disease[20]){
	for(int i=0; i<20; i++){
		if(arr[i]==disease[i] && arr[i]==1){
			switch (i) {
				case 0: cout<<"Problem is ongoing"<<endl;   break;
				case 1: cout<<"Problem is recent"<<endl;   break;
				case 2: cout<<"Problem is sudden"<<endl;   break;
				case 3: cout<<"Preceded by eating suspect food"<<endl;   break;
				case 4: cout<<"Preceded by recent antiobiotic use"<<endl;   break;
				case 5: cout<<"Triggered or worsened by eating certain foods"<<endl;   break;
				case 6: cout<<"Relieved by avoiding certain foods"<<endl;   break;
				case 7: cout<<"Accompanied by abdominal pain or cramping"<<endl;   break;
				case 8: cout<<"Accompanied by bloating or abdominal swelling"<<endl;   break;
				case 9: cout<<"Accompanied by bloody stools"<<endl;   break;
				case 10: cout<<"Accompanied by decreased energy or fatigue"<<endl;   break;
				case 11: cout<<"Accompanied by fever"<<endl;   break;
				case 12: cout<<"Accompanied by foul-smelling stools"<<endl;   break;
				case 13: cout<<"Accompanied by hallucinations"<<endl;   break;
				case 14: cout<<"Accompanied by mucus in stools"<<endl;   break;
				case 15: cout<<"Accompanied by muscle or joint aches"<<endl;   break;
				case 16: cout<<"Accompanied by nausea or vomiting"<<endl;   break;
				case 17: cout<<"Accompanied by passing gas"<<endl;   break;
				case 18: cout<<"Accompanied by stomach growling or rumbling"<<endl;   break;
				case 19: cout<<"Accompanied by weight loss"<<endl;   break;
			}
			
		}
	}
	
}
void printremainingsymptomsDC(bool arr[20], bool disease[20]){
	
	bool remainingsymptomspresent=false;
	
	for(int i=0; i<20; i++){
		if(arr[i]!=disease[i] && disease[i]==1){
			remainingsymptomspresent=true;
		}
	}
	if(remainingsymptomspresent==true){
		cout<<"OTHER SYMPTOMS INCLUDE:"<<endl;
	
	for(int i =0; i<20; i++){
		if(arr[i]!=disease[i] && disease[i]==1){
			switch (i) {
				case 0: cout<<"Problem is ongoing"<<endl;   break;
				case 1: cout<<"Problem is recent"<<endl;   break;
				case 2: cout<<"Problem is sudden"<<endl;   break;
				case 3: cout<<"Preceded by eating suspect food"<<endl;   break;
				case 4: cout<<"Preceded by recent antiobiotic use"<<endl;   break;
				case 5: cout<<"Triggered or worsened by eating certain foods"<<endl;   break;
				case 6: cout<<"Relieved by avoiding certain foods"<<endl;   break;
				case 7: cout<<"Accompanied by abdominal pain or cramping"<<endl;   break;
				case 8: cout<<"Accompanied by bloating or abdominal swelling"<<endl;   break;
				case 9: cout<<"Accompanied by bloody stools"<<endl;   break;
				case 10: cout<<"Accompanied by decreased energy or fatigue"<<endl;   break;
				case 11: cout<<"Accompanied by fever"<<endl;   break;
				case 12: cout<<"Accompanied by foul-smelling stools"<<endl;   break;
				case 13: cout<<"Accompanied by hallucinations"<<endl;   break;
				case 14: cout<<"Accompanied by mucus in stools"<<endl;   break;
				case 15: cout<<"Accompanied by muscle or joint aches"<<endl;   break;
				case 16: cout<<"Accompanied by nausea or vomiting"<<endl;   break;
				case 17: cout<<"Accompanied by passing gas"<<endl;   break;
				case 18: cout<<"Accompanied by stomach growling or rumbling"<<endl;   break;
				case 19: cout<<"Accompanied by weight loss"<<endl;   break;
			}
		}
		
	}
}
	
	
}
void matchDiarrheaChildAntibioticAssociated(bool arr[20]){
	
	
    bool AntibioticAssociatedAns[20]={0,1,0,0,1,0,0,1,0,1,0,1,0,0,1,0,1,0,0,0};

	bool antibioticassociated=false;
	for(int i=0; i<41; i++){
		if(arr[i]==AntibioticAssociatedAns[i]){
			antibioticassociated=true;
			
		}
	}
	if(antibioticassociated==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH ANTIOBIOTIC ASSOCIATED DIARRHEA  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH \n";
		printmatchingsymptomsDC(arr, AntibioticAssociatedAns);
		printremainingsymptomsDC(arr, AntibioticAssociatedAns);
		cout<<"\n \n";
	}
}
void matchDiarrheaChildGiardiaInfection(bool arr[20]){
	 bool GiardiaAns[20]={0,0,1,0,0,0,0,1,1,0,1,0,1,0,0,0,0,1,0,1};

	bool giardia=false;
	for(int i=0; i<20; i++){
		if(arr[i]==GiardiaAns[i]){
			giardia=true;
			
		}
	}
	if(giardia==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH GIARDIA INFECTION  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsDC(arr, GiardiaAns);
		printremainingsymptomsDC(arr, GiardiaAns);
		cout<<"\n \n";
	}
}
void matchDiarrheaChildLactInt(bool arr[20]){
	 bool LactIntAns[20]={1,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,1,1,1,0};

	bool lactose=false;
	for(int i=0; i<20; i++){
		if(arr[i]==LactIntAns[i]){
			lactose=true;
			
		}
	}
	if(lactose==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH LACTOSE INTOLERANCE  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsDC(arr, LactIntAns);
		printremainingsymptomsDC(arr, LactIntAns);
		cout<<"\n \n";
	}
}
void matchDiarrheaChildTravelersDiarrhae(bool arr[20]){
	 bool TravelersDiarrheaAns[20]={0,1,0,1,0,0,0,1,1,0,0,1,0,0,0,0,1,0,0,0};

	bool travelers=false;
	for(int i=0; i<20; i++){
		if(arr[i]==TravelersDiarrheaAns[i]){
			travelers=true;
			
		}
	}
	if(travelers==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH TRAVELER`S DIARRHEA  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsDC(arr, TravelersDiarrheaAns);
		printremainingsymptomsDC(arr, TravelersDiarrheaAns);
		cout<<"\n \n";
	}
}
void matchDiarrheaChildVGas(bool arr[20]){
	 bool VGasAns[20]={0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,1,1,0,0,0};

	bool gastroenteritis=false;
	for(int i=0; i<20; i++){
		if(arr[i]==VGasAns[i]){
			gastroenteritis=true;
			
		}
	}
	if(gastroenteritis==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH VIRAL GASTROENTERITIS \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsDC(arr, VGasAns);
		printremainingsymptomsDC(arr, VGasAns);
		cout<<"\n \n";
	}
}
void matchDiarrheaChildFoodPoison(bool arr[20]){
	 bool FoodPoisonAns[20]={0,0,1,1,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0};

	bool foodpoison=false;
	for(int i=0; i<20; i++){
		if(arr[i]==FoodPoisonAns[i]){
			foodpoison=true;
			
		}
	}
	if(foodpoison==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH FOOD POISONING  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsDC(arr, FoodPoisonAns);
		printremainingsymptomsDC(arr, FoodPoisonAns);
		cout<<"\n \n";
	}
}
void matchDiarrheaChildRotavirus(bool arr[20]){
	 bool RTVAns[20]={0,0,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,0,0,0};

	bool rota=false;
	for(int i=0; i<20; i++){
		if(arr[i]==RTVAns[i]){
			rota=true;
			
		}
	}
	if(rota==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH ROTAVIRUS  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsDC(arr, RTVAns);
		printremainingsymptomsDC(arr, RTVAns);
		cout<<"\n \n";
	}
}
void matchDiarrheaChildShigIn(bool arr[20]){
	 bool SIAns[20]={0,0,1,0,0,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0};

	bool si=false;
	for(int i=0; i<20; i++){
		if(arr[i]==SIAns[i]){  
			si=true;
			
		}
	}
	if(si==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH SHIGELLA INFECTION  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsDC(arr, SIAns);
		printremainingsymptomsDC(arr, SIAns);
		cout<<"\n \n";
	}
}
void printmatchingsymptomsNC(bool arr[31], bool disease[31]){
	for(int i=0; i<31; i++){
		if(arr[i]==disease[i] && arr[i]==1){
			switch (i) {
				case 0: cout<<"Problem is new or recent"<<endl;   break;
				case 1: cout<<"Problem is ongoing"<<endl;   break;
				case 2: cout<<"Problem is recent and worsening"<<endl;   break;
				case 3: cout<<"Nasal discharge is clear or watery"<<endl;   break;
				case 4: cout<<"Nasal discharge is mainly from one side"<<endl;   break;
				case 5: cout<<"Nasal discharge is yellow or greenish"<<endl;   break;
				case 6: cout<<"Accompanied by bad breath"<<endl;   break;
				case 7: cout<<"Accompanied by blue=colored skin under the eyes"<<endl;   break;
				case 8: cout<<"Accompanied by cough"<<endl;   break;
				case 9: cout<<"Accompanied by decreased energy or fatigue"<<endl;   break;
				case 10: cout<<"Accompanied by delayed growth"<<endl;   break;
				case 11: cout<<"Accompanied by ear pain"<<endl;   break;
				case 12: cout<<"Accompanied by enlargement or rounding of fingertips or toes"<<endl;   break;
				case 13: cout<<"Accompanied by failure to thrive(infant and toddler)"<<endl;   break;
				case 14: cout<<"Accompanied by fatigue"<<endl;   break;
				case 15: cout<<"Accompanied by fever"<<endl;   break;
				case 16: cout<<"Accompanied by foul odor or bad breath"<<endl;   break;
				case 17: cout<<"Accompanied by foul=smelling stools"<<endl;   break;
				case 18: cout<<"Accompanied by headache or facial pain"<<endl;   break;
				case 19: cout<<"Accompanied by itchy eyes, nose, mouth or throat"<<endl;   break;
				case 20: cout<<"Accompanied by mild body aches"<<endl;   break;
				case 21: cout<<"Accompanied by nosebleeds"<<endl;   break;
				case 22: cout<<"Accompanied by object in nostril"<<endl;   break;
				case 23: cout<<"Accompanied by recurrent, severe respiratory infections"<<endl;   break;
				case 24: cout<<"Accompanied by reduced sense of smell or taste"<<endl;   break;
				case 25: cout<<"Accompanied by runny nose"<<endl;   break;
				case 26: cout<<"Accompanied by sneezing"<<endl;   break;
				case 27: cout<<"Accompanied by snoring"<<endl;   break;
				case 28: cout<<"Accompanied by sore throat"<<endl;   break;
				case 29: cout<<"Accompanied by upper jaw or tooth pain"<<endl;   break;
				case 30: cout<<"Accompanied by watery eyes"<<endl;   break;

			}
			
		}
	}
	
}
void printremainingsymptomsNC(bool arr[31], bool disease[31]){
	
	bool remainingsymptomspresent=false;
	
	for(int i=0; i<31; i++){
		if(arr[i]!=disease[i] && disease[i]==1){
			remainingsymptomspresent=true;
		}
	}
	if(remainingsymptomspresent==true){
		cout<<"OTHER SYMPTOMS INCLUDE:"<<endl;
	
	for(int i =0; i<31; i++){
		if(arr[i]!=disease[i] && disease[i]==1){
			switch (i) {
				case 0: cout<<"Problem is new or recent"<<endl;   break;
				case 1: cout<<"Problem is ongoing"<<endl;   break;
				case 2: cout<<"Problem is recent and worsening"<<endl;   break;
				case 3: cout<<"Nasal discharge is clear or watery"<<endl;   break;
				case 4: cout<<"Nasal discharge is mainly from one side"<<endl;   break;
				case 5: cout<<"Nasal discharge is yellow or greenish"<<endl;   break;
				case 6: cout<<"Accompanied by bad breath"<<endl;   break;
				case 7: cout<<"Accompanied by blue=colored skin under the eyes"<<endl;   break;
				case 8: cout<<"Accompanied by cough"<<endl;   break;
				case 9: cout<<"Accompanied by decreased energy or fatigue"<<endl;   break;
				case 10: cout<<"Accompanied by delayed growth"<<endl;   break;
				case 11: cout<<"Accompanied by ear pain"<<endl;   break;
				case 12: cout<<"Accompanied by enlargement or rounding of fingertips or toes"<<endl;   break;
				case 13: cout<<"Accompanied by failure to thrive(infant and toddler)"<<endl;   break;
				case 14: cout<<"Accompanied by fatigue"<<endl;   break;
				case 15: cout<<"Accompanied by fever"<<endl;   break;
				case 16: cout<<"Accompanied by foul odor or bad breath"<<endl;   break;
				case 17: cout<<"Accompanied by foul=smelling stools"<<endl;   break;
				case 18: cout<<"Accompanied by headache or facial pain"<<endl;   break;
				case 19: cout<<"Accompanied by itchy eyes, nose, mouth or throat"<<endl;   break;
				case 20: cout<<"Accompanied by mild body aches"<<endl;   break;
				case 21: cout<<"Accompanied by nosebleeds"<<endl;   break;
				case 22: cout<<"Accompanied by object in nostril"<<endl;   break;
				case 23: cout<<"Accompanied by recurrent, severe respiratory infections"<<endl;   break;
				case 24: cout<<"Accompanied by reduced sense of smell or taste"<<endl;   break;
				case 25: cout<<"Accompanied by runny nose"<<endl;   break;
				case 26: cout<<"Accompanied by sneezing"<<endl;   break;
				case 27: cout<<"Accompanied by snoring"<<endl;   break;
				case 28: cout<<"Accompanied by sore throat"<<endl;   break;
				case 29: cout<<"Accompanied by upper jaw or tooth pain"<<endl;   break;
				case 30: cout<<"Accompanied by watery eyes"<<endl;   break;
			}
		}
		
	}
}
	
	
}
void matchNaCoChildActSinusitis(bool arr[31]){
	
	
    bool ActSinusitisAns[31]={1,0,0,0,0,1,1,0,1,0,0,1,0,0,1,1,0,0,1,0,0,0,0,0,1,0,1,0,1,0,1};

	bool sinusitis=false;
	for(int i=0; i<31; i++){
		if(arr[i]==ActSinusitisAns[i]){
			sinusitis=true;
			
		}
	}
	if(sinusitis==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH ACUTE SINUSITIS  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH \n";
		printmatchingsymptomsNC(arr, ActSinusitisAns);
		printremainingsymptomsNC(arr, ActSinusitisAns);
		cout<<"\n \n";
	}
}
void matchNaCoChildChrSinusitis(bool arr[31]){
	 bool ChrSinusitisAns[31]={0,1,0,0,0,1,1,0,1,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,1,1,0};

	bool csinus=false;
	for(int i=0; i<31; i++){
		if(arr[i]==ChrSinusitisAns[i]){
			csinus=true;
			
		}
	}
	if(csinus==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH CRONICH SINUSITIS  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsNC(arr, ChrSinusitisAns);
		printremainingsymptomsNC(arr, ChrSinusitisAns);
		cout<<"\n \n";
	}
}
void matchNaCoChildComCold(bool arr[31]){
	 bool ComColdAns[31]={1,0,0,1,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,1,1,0,1,0,1};

	bool cold=false;
	for(int i=0; i<31; i++){
		if(arr[i]==ComColdAns[i]){
			cold=true;
			
		}
	}
	if(cold==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH THE COMMON COLD  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsNC(arr, ComColdAns);
		printremainingsymptomsNC(arr, ComColdAns);
		cout<<"\n \n";
	}
}
void matchNaCoHayFever(bool arr[31]){
	 bool HayFeverAns[31]={0,1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,1};

	bool hfever=false;
	for(int i=0; i<31; i++){
		if(arr[i]==HayFeverAns[i]){
			hfever=true;
			
		}
	}
	if(hfever==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH HAY FEVER  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsNC(arr, HayFeverAns);
		printremainingsymptomsNC(arr, HayFeverAns);
		cout<<"\n \n";
	}
}
void matchNaCoChildCF(bool arr[31]){
	 bool CFAns[31]={0,1,0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0};

	bool cf=false;
	for(int i=0; i<31; i++){
		if(arr[i]==CFAns[i]){
			cf=true;
			
		}
	}
	if(cf==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH CYSTIC FIBROSIS \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsNC(arr, CFAns);
		printremainingsymptomsNC(arr, CFAns);
		cout<<"\n \n";
	}
}
void matchNaCoChildFOITN(bool arr[31]){
	 bool FOITNAns[31]={0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0};

	bool object=false;
	for(int i=0; i<31; i++){
		if(arr[i]==FOITNAns[i]){
			object=true;
			
		}
	}
	if(object==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH FOREIGN OBJECT IN THE NOSE  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsNC(arr, FOITNAns);
		printremainingsymptomsNC(arr, FOITNAns);
		cout<<"\n \n";
	}
}
void matchNaCoNARhin(bool arr[31]){
	 bool RhinitisAns[31]={0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1};

	bool rhin=false;
	for(int i=0; i<31; i++){
		if(arr[i]==RhinitisAns[i]){
			rhin=true;
			
		}
	}
	if(rhin==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH ENDOMETRIOSIS  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsNC(arr, RhinitisAns);
		printremainingsymptomsNC(arr, RhinitisAns);
		cout<<"\n \n";
	}
}
void matchNaCoChildNP(bool arr[31]){
	 bool NPAns[31]={0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0};

	bool np=false;
	for(int i=0; i<31; i++){
		if(arr[i]==NPAns[i]){
			np=true;
			
		}
	}
	if(np==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH NASAL POLYPS  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsNC(arr, NPAns);
		printremainingsymptomsNC(arr, NPAns);
		cout<<"\n \n";
	}
}
void matchNaCoChildDS(bool arr[31]){
	 bool DSAns[31]={0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0};

	bool ds=false;
	for(int i=0; i<31; i++){
		if(arr[i]==DSAns[i]){
			ds=true;
			
		}
	}
	if(ds==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH DEVIATED SEPTUM  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsNC(arr, DSAns);
		printremainingsymptomsNC(arr, DSAns);
		cout<<"\n \n";
	}
}
void printmatchingsymptomsSR(bool arr[36], bool disease[36]) {
	for (int i = 0; i < 36; i++) {
		if (arr[i] == disease[i] && arr[i] == 1) {
			switch (i) {
			case 0: cout << "Rash best described as blisters" << endl;   break;
			case 1: cout << "Rash best described as itchy" << endl;   break;
			case 2: cout << "Rash best described as lacy and slightly raised" << endl;   break;
			case 3: cout << "Rash best described as oozing sores that become crusty" << endl;   break;
			case 4: cout << "Rash best described as pus-filled,crusty swellings" << endl;   break;
			case 5: cout << "Rash best described as Raised red welts" << endl;   break;
			case 6: cout << "Rash best described as red or discoloured blotches" << endl;   break;
			case 7: cout << "Rash best described as ring shaped" << endl;   break;
			case 8: cout << "Rash best described as scaly or flaky" << endl;   break;
			case 9: cout << "Rash best described as thick and leathery" << endl;   break;
			case 10: cout << "affects a small site and then spreads" << endl;   break;
			case 11: cout << "affects diaper area" << endl;   break;
			case 12: cout << "affects face or neck" << endl;   break;
			case 13: cout << "affects folds of skin" << endl;   break;
			case 14: cout << "affects genital area" << endl;   break;
			case 15: cout << "affects hands or feet" << endl;   break;
			case 16: cout << "affects scalp" << endl;   break;
			case 17: cout << "affects trunk" << endl;   break;
			case 18: cout << "preceeded by eating certain foods " << endl;   break;
			case 19: cout << "preceeded by exposure to allergen or irritant" << endl;   break;
			case 20: cout << "preceeded by exposure to irritating plants" << endl;   break;
			case 21: cout << "preceeded by prolonged exposure to heat" << endl;   break;
			case 22: cout << "preceeded by tick bite or possible exposure to ticks" << endl;   break;
			case 23: cout << "accompanied by brittle hair and hairloss" << endl;   break;
			case 24: cout << "accompanied by dandruff" << endl;   break;
			case 25: cout << "accompanied by diarrhea" << endl;   break;
			case 26: cout << "accompanied by difficulty breathing" << endl;   break;
			case 27: cout << "accompanied by fever" << endl;   break;
			case 28: cout << "accompanied by hedache" << endl;   break;
			case 29: cout << "accompanied by joint pain" << endl;   break;
			case 30: cout << "accompanied by loss of appetite" << endl;   break;
			case 31: cout << "accompanied by mouth or tongue sores" << endl;   break;
			case 32: cout << "accompanied by muscle aches or pain" << endl;   break;
			case 33: cout << "accompanied by nausea or vomiting" << endl;   break;
			case 34: cout << "accompanied by sore throat" << endl;   break;
			case 35: cout << "accompanied by swelling of lips,face or tongue" << endl;   break;
			}

		}
	}

}
void printremainingsymptomsSR(bool arr[36], bool disease[36]) {

	bool remainingsymptomspresent = false;

	for (int i = 0; i < 36; i++) {
		if (arr[i] != disease[i] && disease[i] == 1) {
			remainingsymptomspresent = true;
		}
	}
	if (remainingsymptomspresent == true) {
		cout << "OTHER SYMPTOMS INCLUDE:" << endl;

		for (int i = 0; i < 36; i++) {
			if (arr[i] != disease[i] && disease[i] == 1) {
				switch (i) {
				case 0: cout << "Rash best described as blisters" << endl;   break;
				case 1: cout << "Rash best described as itchy" << endl;   break;
				case 2: cout << "Rash best described as lacy and slightly raised" << endl;   break;
				case 3: cout << "Rash best described as oozing sores that become crusty" << endl;   break;
				case 4: cout << "Rash best described as pus-filled,crusty swellings" << endl;   break;
				case 5: cout << "Rash best described as Raised red welts" << endl;   break;
				case 6: cout << "Rash best described as red or discoloured blotches" << endl;   break;
				case 7: cout << "Rash best described as ring shaped" << endl;   break;
				case 8: cout << "Rash best described as scaly or flaky" << endl;   break;
				case 9: cout << "Rash best described as thick and leathery" << endl;   break;
				case 10: cout << "affects a small site and then spreads" << endl;   break;
				case 11: cout << "affects diaper area" << endl;   break;
				case 12: cout << "affects face or neck" << endl;   break;
				case 13: cout << "affects folds of skin" << endl;   break;
				case 14: cout << "affects genital area" << endl;   break;
				case 15: cout << "affects hands or feet" << endl;   break;
				case 16: cout << "affects scalp" << endl;   break;
				case 17: cout << "affects trunk" << endl;   break;
				case 18: cout << "preceeded by eating certain foods " << endl;   break;
				case 19: cout << "preceeded by exposure to allergen or irritant" << endl;   break;
				case 20: cout << "preceeded by exposure to irritating plants" << endl;   break;
				case 21: cout << "preceeded by prolonged exposure to heat" << endl;   break;
				case 22: cout << "preceeded by tick bite or possible exposure to ticks" << endl;   break;
				case 23: cout << "accompanied by brittle hair and hairloss" << endl;   break;
				case 24: cout << "accompanied by dandruff" << endl;   break;
				case 25: cout << "accompanied by diarrhea" << endl;   break;
				case 26: cout << "accompanied by difficulty breathing" << endl;   break;
				case 27: cout << "accompanied by fever" << endl;   break;
				case 28: cout << "accompanied by hedache" << endl;   break;
				case 29: cout << "accompanied by joint pain" << endl;   break;
				case 30: cout << "accompanied by loss of appetite" << endl;   break;
				case 31: cout << "accompanied by mouth or tongue sores" << endl;   break;
				case 32: cout << "accompanied by muscle aches or pain" << endl;   break;
				case 33: cout << "accompanied by nausea or vomiting" << endl;   break;
				case 34: cout << "accompanied by sore throat" << endl;   break;
				case 35: cout << "accompanied by swelling of lips,face or tongue" << endl;   break;
				}
			}

		}
	}


}
void matchfoodallergy(bool arr[36]) {


	bool foodallergyAns[36] = { 0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1,0,1 };

	bool foodallergy = false;
	for (int i = 0; i < 36; i++) {
		if (arr[i] == foodallergyAns[i]) {
			foodallergy = true;

		}
	}
	if (foodallergy == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH FOOD ALLERGY \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH \n";
		printmatchingsymptomsSR(arr, foodallergyAns);
		printremainingsymptomsSR(arr, foodallergyAns);
		cout << "\n \n";
	}
}
void matchlymedisease(bool arr[36]) {
	bool lymediseaseAns[36] = { 0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,0,0 };

	bool lymedisease = false;
	for (int i = 0; i < 36; i++) {
		if (arr[i] == lymediseaseAns[i]) {
			lymedisease = true;

		}
	}
	if (lymedisease == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH LYME DISEASE  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsSR(arr, lymediseaseAns);
		printremainingsymptomsSR(arr, lymediseaseAns);
		cout << "\n \n";
	}
}
void matchparvovirusinfection(bool arr[36]) {
	bool parvovirusinfectionAns[36] = { 0,1,1,0,0,0,1,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,1,0 };

	bool parvovirusinfection = false;
	for (int i = 0; i < 36; i++) {
		if (arr[i] == parvovirusinfectionAns[i]) {
			parvovirusinfection = true;

		}
	}
	if (parvovirusinfection == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH PAROVIRUS INFECTION  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsSR(arr, parvovirusinfectionAns);
		printremainingsymptomsSR(arr, parvovirusinfectionAns);
		cout << "\n \n";
	}
}
void matchringworm(bool arr[36]) {
	bool matchringwormAns[36] = { 0,1,0,0,1,0,0,1,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0 };

	bool matchringworm = false;
	for (int i = 0; i < 36; i++) {
		if (arr[i] == matchringwormAns[i]) {
			matchringworm = true;

		}
	}
	if (matchringworm == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH RING WORM  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsSR(arr, matchringwormAns);
		printremainingsymptomsSR(arr, matchringwormAns);
		cout << "\n \n";
	}
}
void matchhandfootmouthdisease(bool arr[36]) {
	bool handfootmouthdiseaseAns[36] = { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,0,1,0 };

	bool handfootmouthdisease = false;
	for (int i = 0; i < 36; i++) {
		if (arr[i] == handfootmouthdiseaseAns[i]) {
			handfootmouthdisease = true;

		}
	}
	if (handfootmouthdisease == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH HAND-FOOT-MOUTH DISEASE \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsSR(arr, handfootmouthdiseaseAns);
		printremainingsymptomsSR(arr, handfootmouthdiseaseAns);
		cout << "\n \n";
	}
}
void matchseborrheicdermatitis(bool arr[36]) {
	bool seborrheicdermatitisAns[36] = { 0,1,0,0,0,0,0,0,1,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	bool seborrheicdermatitis = false;
	for (int i = 0; i < 36; i++) {
		if (arr[i] == seborrheicdermatitisAns[i]) {
			seborrheicdermatitis = true;

		}
	}
	if (seborrheicdermatitis == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH SABORREIC DERMATITIS  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsSR(arr, seborrheicdermatitisAns);
		printremainingsymptomsSR(arr, seborrheicdermatitisAns);
		cout << "\n \n";
	}
}
void matchcradlecap(bool arr[36]) {
	bool cradlecapAns[36] = { 0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0 };

	bool cradlecap = false;
	for (int i = 0; i < 36; i++) {
		if (arr[i] == cradlecapAns[i]) {
			cradlecap = true;

		}
	}
	if (cradlecap == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH CRADLE CRAP  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsSR(arr, cradlecapAns);
		printremainingsymptomsSR(arr, cradlecapAns);
		cout << "\n \n";
	}
}
void matchheatrash(bool arr[36]) {
	bool heatrashAns[36] = { 0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	bool heatrash = false;
	for (int i = 0; i < 36; i++) {
		if (arr[i] == heatrashAns[i]) {
			heatrash = true;

		}
	}
	if (heatrash == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH HEATRASH \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsSR(arr, heatrashAns);
		printremainingsymptomsSR(arr, heatrashAns);
		cout << "\n \n";
	}
}
void matchimpetigo(bool arr[36]) {
	bool impetigoAns[36] = { 1,1,0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };

	bool impetigo = false;
	for (int i = 0; i < 36; i++) {
		if (arr[i] == impetigoAns[i]) {
			impetigo = true;

		}
	}
	if (impetigo == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH IMPETIGO  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsSR(arr, impetigoAns);
		printremainingsymptomsSR(arr, impetigoAns);
		cout << "\n \n";
	}
}
void printmatchingsymptomsNV(bool arr[20], bool disease[20]) {
	for (int i = 0; i < 20; i++) {
		if (arr[i] == disease[i] && arr[i] == 1) {
			switch (i) {
			case 0: cout << "triggered or worsened by eating certain foods" << endl;   break;
			case 1: cout << "triggered or worsened by travel or motion" << endl;   break;
			case 2: cout << "onset is internittent or episodic " << endl;   break;
			case 3: cout << "onset is recent" << endl;   break;
			case 4: cout << "onset is sudden" << endl;   break;
			case 5: cout << "onset is within the first two months of life" << endl;   break;
			case 6: cout << "accompanied by abdominal bloating or swallowing " << endl;   break;
			case 7: cout << "accompanied by abdominal pain,discomfort or cramps" << endl;   break;
			case 8: cout << "accompanied abdominal pain that is severe or progressive " << endl;   break;
			case 9: cout << "accompanied by constipation" << endl;   break;
			case 10: cout << "accompanied by cough" << endl;   break;
			case 11: cout << "accompanied by diarrhea " << endl;   break;
			case 12: cout << "accompanied by dizziness" << endl;   break;
			case 13: cout << "accompanied by failure to thrive or gain weight(infant)" << endl;   break;
			case 14: cout << "accompanied by fever" << endl;   break;
			case 15: cout << "accompanied by fussiness or irritability" << endl;   break;
			case 16: cout << "accompanied by hives or rash" << endl;   break;
			case 17: cout << "accompanied by swelling or tingling of lips,face and tongue" << endl;   break;
			case 18: cout << "accompanied by wet burps or spit up" << endl;   break;
			case 19: cout << "accompanied by wheezing" << endl;   break;

			}

		}
	}

}
void printremainingsymptomsNV(bool arr[20], bool disease[20]) {

	bool remainingsymptomspresent = false;

	for (int i = 0; i < 20; i++) {
		if (arr[i] != disease[i] && disease[i] == 1) {
			remainingsymptomspresent = true;
		}
	}
	if (remainingsymptomspresent == true) {
		cout << "OTHER SYMPTOMS INCLUDE:" << endl;

		for (int i = 0; i < 20; i++) {
			if (arr[i] != disease[i] && disease[i] == 1) {
				switch (i) {
				case 0: cout << "triggered or worsened by eating certain foods" << endl;   break;
				case 1: cout << "triggered or worsened by travel or motion" << endl;   break;
				case 2: cout << "onset is internittent or episodic " << endl;   break;
				case 3: cout << "onset is recent" << endl;   break;
				case 4: cout << "onset is sudden" << endl;   break;
				case 5: cout << "onset is within the first two months of life" << endl;   break;
				case 6: cout << "accompanied by abdominal bloating or swallowing " << endl;   break;
				case 7: cout << "accompanied by abdominal pain,discomfort or cramps" << endl;   break;
				case 8: cout << "accompanied abdominal pain that is severe or progressive " << endl;   break;
				case 9: cout << "accompanied by constipation" << endl;   break;
				case 10: cout << "accompanied by cough" << endl;   break;
				case 11: cout << "accompanied by diarrhea " << endl;   break;
				case 12: cout << "accompanied by dizziness" << endl;   break;
				case 13: cout << "accompanied by failure to thrive or gain weight(infant)" << endl;   break;
				case 14: cout << "accompanied by fever" << endl;   break;
				case 15: cout << "accompanied by fussiness or irritability" << endl;   break;
				case 16: cout << "accompanied by hives or rash" << endl;   break;
				case 17: cout << "accompanied by swelling or tingling of lips,face and tongue" << endl;   break;
				case 18: cout << "accompanied by wet burps or spit up" << endl;   break;
				case 19: cout << "accompanied by wheezing" << endl;   break;
				}
			}

		}
	}


}
void matchFoodallergy(bool arr[20]) {


	bool FoodallergyAns[20] = { 1,0,1,0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0,1 };

	bool Foodallergy = false;
	for (int i = 0; i < 20; i++) {
		if (arr[i] == FoodallergyAns[i]) {
			Foodallergy = true;

		}
	}
	if (Foodallergy == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH FOOD ALLERGY  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH \n";
		printmatchingsymptomsNV(arr, FoodallergyAns);
		printremainingsymptomsNV(arr, FoodallergyAns);
		cout << "\n \n";
	}
}
void matchFoodpoisoning(bool arr[20]) {
	bool FoodpoisoningAns[20] = { 1,0,0,0,1,0,1,1,0,0,0,1,0,0,1,0,0,0,0,0 };

	bool Foodpoisoning = false;
	for (int i = 0; i < 20; i++) {
		if (arr[i] == FoodpoisoningAns[i]) {
			Foodpoisoning = true;

		}
	}
	if (Foodpoisoning == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH FOOD POISONING  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsNV(arr, FoodpoisoningAns);
		printremainingsymptomsNV(arr, FoodpoisoningAns);
		cout << "\n \n";
	}
}
void matchAppendicitis(bool arr[20]) {
	bool AppendicitisAns[20] = { 0,0,0,1,0,0,0,0,1,1,0,1,0,0,1,0,0,0,0,0 };

	bool Appendicitis = false;
	for (int i = 0; i < 20; i++) {
		if (arr[i] == AppendicitisAns[i]) {
			Appendicitis = true;

		}
	}
	if (Appendicitis == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH APPENDICITIS  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsNV(arr, AppendicitisAns);
		printremainingsymptomsNV(arr, AppendicitisAns);
		cout << "\n \n";
	}
}
void matchInfantreflux(bool arr[20]) {
	bool InfantrefluxAns[20] = { 0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0,1,1 };

	bool Infantreflux = false;
	for (int i = 0; i < 20; i++) {
		if (arr[i] == InfantrefluxAns[i]) {
			Infantreflux = true;

		}
	}
	if (Infantreflux == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH INFANT REFLUX  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsNV(arr, InfantrefluxAns);
		printremainingsymptomsNV(arr, InfantrefluxAns);
		cout << "\n \n";
	}
}
void matchMotionsickness(bool arr[20]) {
	bool MotionsicknessAns[20] = { 0,1,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0 };

	bool Motionsickness = false;
	for (int i = 0; i < 20; i++) {
		if (arr[i] == MotionsicknessAns[i]) {
			Motionsickness = true;

		}
	}
	if (Motionsickness == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH MOTION SICKNESS \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsNV(arr, MotionsicknessAns);
		printremainingsymptomsNV(arr, MotionsicknessAns);
		cout << "\n \n";
	}
}
void matchViralgastroenteritis(bool arr[20]) {
	bool ViralgastroenteritisAns[20] = { 1,0,0,1,0,0,0,1,0,0,0,1,0,0,1,0,0,0,0,0 };

	bool Viralgastroenteritis = false;
	for (int i = 0; i < 20; i++) {
		if (arr[i] == ViralgastroenteritisAns[i]) {
			Viralgastroenteritis = true;

		}
	}
	if (Viralgastroenteritis == true) {
		cout << "A FEW OF YOUR SYMPTOMS MATCH WITH VIRAL GASTROENTIRITIS  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsNV(arr, ViralgastroenteritisAns);
		printremainingsymptomsNV(arr, ViralgastroenteritisAns);
		cout << "\n \n";
	}
}
void printmatchingsymptomsHC(bool arr[31], bool disease[31]){
	for(int i=0; i<31; i++){
		if(arr[i]==disease[i] && arr[i]==1){
			switch (i) {
				case 0: cout<<"pain is Intense"<<endl;   break;
				case 1: cout<<"pain is Pressure or squeezing sensation"<<endl;   break;
				case 2: cout<<"pain is mild to moderate"<<endl;   break;
				case 3: cout<<"pain is stabbing"<<endl;   break;
				case 4: cout<<"pain located around one eye or radiates from one eye"<<endl;   break;
				case 5: cout<<"pain located on one side of head"<<endl;   break;
				case 6: cout<<"pain located on both sides of head"<<endl;   break;
				case 7: cout<<"Onset is Gradual"<<endl;   break;
				case 8: cout<<"Onset is preceded by visual or other sensory disturbances"<<endl;   break;
				case 9: cout<<"Onset is preceded by head injury or fall"<<endl;   break;
				case 10: cout<<"Onset is preceded by sudden"<<endl;   break;
				case 11: cout<<"Duration of headache is a few hours to day"<<endl;   break;
				case 12: cout<<"Duration of headache is a few minutes to hours"<<endl;   break;
				case 13: cout<<"Recurrence of headache gradually becomes more frequent"<<endl;   break;
				case 14: cout<<"Recurrence of headache is often in morning "<<endl;   break;
				case 15: cout<<"Recurrence of headache is daily"<<endl;   break;
				case 16: cout<<"Recurrence of headache is often same time everyday"<<endl;   break;
				case 17: cout<<"Triggered or worsened by change in sleep patterns"<<endl;   break;
				case 18: cout<<"Triggered or worsened by hormonal changes"<<endl;   break;
				case 19: cout<<"Triggered or worsened by clenching"<<endl;   break;
				case 20: cout<<"Triggered or worsened by poor posture"<<endl;   break;
				case 21: cout<<"Relieved by lying down in dark"<<endl;   break;
				case 22: cout<<"Relieved by rest"<<endl;   break;
				case 23: cout<<"Relieved by over the counter pain medication"<<endl;   break;
				case 24: cout<<"accompanied by achy joints or muscles"<<endl;   break;
				case 25: cout<<"accompanied by nausea or vomiting"<<endl;   break;
				case 26: cout<<"accompanied by change in personality "<<endl;   break;
				case 27: cout<<"accompanied by numbness"<<endl;   break;
				case 28: cout<<"accompanied by confusion"<<endl;   break;
				case 29: cout<<"accompanied by restlessness"<<endl;   break;
				case 30: cout<<"accompanied by difficulty in speaking"<<endl;   break;
			}
			
		}
	}
	
}
void printremainingsymptomsHC(bool arr[31], bool disease[31]){
	
	bool remainingsymptomspresent=false;
	
	for(int i=0; i<31; i++){
		if(arr[i]!=disease[i] && disease[i]==1){
			remainingsymptomspresent=true;
		}
	}
	if(remainingsymptomspresent==true){
		cout<<"OTHER SYMPTOMS INCLUDE:"<<endl;
	
	for(int i =0; i<31; i++){
		if(arr[i]!=disease[i] && disease[i]==1){
			switch (i) {
				case 0: cout<<"pain is Intense"<<endl;   break;
				case 1: cout<<"pain is Pressure or squeezing sensation"<<endl;   break;
				case 2: cout<<"pain is mild to moderate"<<endl;   break;
				case 3: cout<<"pain is stabbing"<<endl;   break;
				case 4: cout<<"pain located around one eye or radiates from one eye"<<endl;   break;
				case 5: cout<<"pain located on one side of head"<<endl;   break;
				case 6: cout<<"pain located on both sides of head"<<endl;   break;
				case 7: cout<<"Onset is Gradual"<<endl;   break;
				case 8: cout<<"Onset is preceded by visual or other sensory disturbances"<<endl;   break;
				case 9: cout<<"Onset is preceded by head injury or fall"<<endl;   break;
				case 10: cout<<"Onset is preceded by sudden"<<endl;   break;
				case 11: cout<<"Duration of headache is a few hours to day"<<endl;   break;
				case 12: cout<<"Duration of headache is a few minutes to hours"<<endl;   break;
				case 13: cout<<"Recurrence of headache gradually becomes more frequent"<<endl;   break;
				case 14: cout<<"Recurrence of headache is often in morning "<<endl;   break;
				case 15: cout<<"Recurrence of headache is daily"<<endl;   break;
				case 16: cout<<"Recurrence of headache is often same time everyday"<<endl;   break;
				case 17: cout<<"Triggered or worsened by change in sleep patterns"<<endl;   break;
				case 18: cout<<"Triggered or worsened by hormonal changes"<<endl;   break;
				case 19: cout<<"Triggered or worsened by clenching"<<endl;   break;
				case 20: cout<<"Triggered or worsened by poor posture"<<endl;   break;
				case 21: cout<<"Relieved by lying down in dark"<<endl;   break;
				case 22: cout<<"Relieved by rest"<<endl;   break;
				case 23: cout<<"Relieved by over the counter pain medication"<<endl;   break;
				case 24: cout<<"accompanied by achy joints or muscles"<<endl;   break;
				case 25: cout<<"accompanied by nausea or vomiting"<<endl;   break;
				case 26: cout<<"accompanied by change in personality "<<endl;   break;
				case 27: cout<<"accompanied by numbness"<<endl;   break;
				case 28: cout<<"accompanied by confusion"<<endl;   break;
				case 29: cout<<"accompanied by restlessness"<<endl;   break;
				case 30: cout<<"accompanied by difficulty in speaking"<<endl;   break;
			}
		}
		
	}
}
	
	
}
void matchMigraine1(bool arr[31]){
	
	
    bool MigraineAns[31]={1,0,0,0,0,1,1,1,1,0,1,1,0,0,0,0,0,1,1,0,0,1,1,1,0,1,0,0,0,0,0};

	bool Migraine=false;
	for(int i=0; i<31; i++){
		if(arr[i]==MigraineAns[i]){
			Migraine=true;
			
		}
	}
	if(Migraine==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Migraine  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH \n";
		printmatchingsymptomsHC(arr, MigraineAns);
		printremainingsymptomsHC(arr, MigraineAns);
		cout<<"\n \n";
	}
}
void matchEncephlitis(bool arr[31]){
	 bool EncephlitisAns[31]={0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0};

	bool Encephlitis=false;
	for(int i=0; i<31; i++){
		if(arr[i]==EncephlitisAns[i]){
			Encephlitis=true;
			
		}
	}
	if(Encephlitis==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Encephlitis DISEASE  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsHC(arr, EncephlitisAns);
		printremainingsymptomsHC(arr, EncephlitisAns);
		cout<<"\n \n";
	}
}
void matchConcussion(bool arr[31]){
	 bool ConcussionAns[31]={0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1,0,1,0,1};

	bool Concussion=false;
	for(int i=0; i<31; i++){
		if(arr[i]==ConcussionAns[i]){
			Concussion=true;
			
		}
	}
	if(Concussion==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Concussion DISEASE  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsHC(arr, ConcussionAns);
		printremainingsymptomsHC(arr, ConcussionAns);
		cout<<"\n \n";
	}
}
void matchMeningitis(bool arr[31]){
	 bool MeningitisAns[31]={0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,1,0,0,1,0,0};

	bool Meningitis=false;
	for(int i=0; i<31; i++){
		if(arr[i]==MeningitisAns[i]){
			Meningitis=true;
			
		}
	}
	if(Meningitis==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Meningitis  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsHC(arr, MeningitisAns);
		printremainingsymptomsHC(arr, MeningitisAns);
		cout<<"\n \n";
	}
}
void matchBrainTumor(bool arr[31]){
	 bool BTAns[31]={0,0,0,0,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1};

	bool BT=false;
	for(int i=0; i<31; i++){
		if(arr[i]==BTAns[i]){
			BT=true;
			
		}
	}
	if(BT==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH BRAIN TUMOR \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsHC(arr, BTAns);
		printremainingsymptomsHC(arr, BTAns);
		cout<<"\n \n";
	}
}
void matchClusterheadache(bool arr[31]){
	 bool ClusterheadacheAns[31]={1,0,0,1,1,0,0,0,0,0,1,0,1,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0};

	bool Clusterheadache=false;
	for(int i=0; i<31; i++){
		if(arr[i]==ClusterheadacheAns[i]){
			Clusterheadache=true;
			
		}
	}
	if(Clusterheadache==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Cluster headache  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsHC(arr, ClusterheadacheAns);
		printremainingsymptomsHC(arr, ClusterheadacheAns);
		cout<<"\n \n";
	}
}
void matchTensionheadache(bool arr[31]){
	 bool TensionheadacheAns[31]={0,1,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0};

	bool Tensionheadache=false;
	for(int i=0; i<31; i++){
		if(arr[i]==TensionheadacheAns[i]){
			Tensionheadache=true;
			
		}
	}
	if(Tensionheadache==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Tension headache  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsHC(arr, TensionheadacheAns);
		printremainingsymptomsHC(arr, TensionheadacheAns);
		cout<<"\n \n";
	}
}
void matchTMJDISORDER(bool arr[31]){
	 bool TMJAns[31]={0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0};

	bool TMJ=false;
	for(int i=0; i<31; i++){
		if(arr[i]==TMJAns[i]){
			TMJ=true;
			
		}
	}
	if(TMJ==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH TMJ DISORDER  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsHC(arr, TMJAns);
		printremainingsymptomsHC(arr, TMJAns);
		cout<<"\n \n";
	}
}
void printmatchingsymptomsSB(bool arr[20], bool disease[20]){
	for(int i=0; i<20; i++){
		if(arr[i]==disease[i] && arr[i]==1){
			switch (i) {
				case 0: cout<<"Problem is new or recent"<<endl;   break;
				case 1: cout<<"Problem is ongoing or recurrent"<<endl;   break;
				case 2: cout<<"Preceded by trauma or injury"<<endl;   break;
				case 3: cout<<"Preceded by upper respiratory illness"<<endl;   break;
				case 4: cout<<"Triggered or worsened by Allergens or irritants"<<endl;   break;
				case 5: cout<<"Triggered or worsened by Exposure to cold air"<<endl;   break;
				case 6: cout<<"Triggered or worsened by Anxiety or stress"<<endl;   break;
				case 7: cout<<"Triggered or worsened by Mild to moderate exertion"<<endl;   break;
				case 8: cout<<"Triggered or worsened by coughing,sneezing or deep breathing"<<endl;   break;
				case 9: cout<<"Triggered or worsened by Smoking"<<endl;   break;
				case 10: cout<<"Accompanied by chest pain or tightness"<<endl;   break;
				case 11: cout<<"Accompanied by irregular or rapid heartbeat"<<endl;   break;
				case 12: cout<<"Accompanied by cough that produces blood"<<endl;   break;
				case 13: cout<<"Accompanied by Nausea"<<endl;   break;
				case 14: cout<<"Accompanied by cough that produces sputum"<<endl;   break;
				case 15: cout<<"Accompanied by Pale or bluish skin"<<endl;   break;
				case 16: cout<<"Accompanied by Dizziness or fainting"<<endl;   break;
				case 17: cout<<"Accompanied by Rapid weight gain"<<endl;   break;
				case 18: cout<<"Accompanied by Dry cough"<<endl;   break;
				case 19: cout<<"Accompanied by Sweating"<<endl;   break;
				
			}
			
		}
	}
	
}
void printremainingsymptomsSB(bool arr[20], bool disease[20]){
	
	bool remainingsymptomspresent=false;
	
	for(int i=0; i<20; i++){
		if(arr[i]!=disease[i] && disease[i]==1){
			remainingsymptomspresent=true;
		}
	}
	if(remainingsymptomspresent==true){
		cout<<"OTHER SYMPTOMS INCLUDE:"<<endl;
	
	for(int i =0; i<20; i++){
		if(arr[i]!=disease[i] && disease[i]==1){
			switch (i) {
				case 0: cout<<"Problem is new or recent"<<endl;   break;
				case 1: cout<<"Problem is ongoing or recurrent"<<endl;   break;
				case 2: cout<<"Preceded by trauma or injury"<<endl;   break;
				case 3: cout<<"Preceded by upper respiratory illness"<<endl;   break;
				case 4: cout<<"Triggered or worsened by Allergens or irritants"<<endl;   break;
				case 5: cout<<"Triggered or worsened by Exposure to cold air"<<endl;   break;
				case 6: cout<<"Triggered or worsened by Anxiety or stress"<<endl;   break;
				case 7: cout<<"Triggered or worsened by Mild to moderate exertion"<<endl;   break;
				case 8: cout<<"Triggered or worsened by coughing,sneezing or deep breathing"<<endl;   break;
				case 9: cout<<"Triggered or worsened by Smoking"<<endl;   break;
				case 10: cout<<"Accompanied by chest pain or tightness"<<endl;   break;
				case 11: cout<<"Accompanied by irregular or rapid heartbeat"<<endl;   break;
				case 12: cout<<"Accompanied by cough that produces blood"<<endl;   break;
				case 13: cout<<"Accompanied by Nausea"<<endl;   break;
				case 14: cout<<"Accompanied by cough that produces sputum"<<endl;   break;
				case 15: cout<<"Accompanied by Pale or bluish skin"<<endl;   break;
				case 16: cout<<"Accompanied by Dizziness or fainting"<<endl;   break;
				case 17: cout<<"Accompanied by Rapid weight gain"<<endl;   break;
				case 18: cout<<"Accompanied by Dry cough"<<endl;   break;
				case 19: cout<<"Accompanied by Sweating"<<endl;   break;
				
			}
		}
		
	}
}
	
	
}
void matchAsthma0(bool arr[20]){
	
	
    bool AsthmaAns[20]={1,1,0,1,1,1,0,1,0,1,1,0,0,0,0,0,0,0,1,0};

	bool Asthma=false;
	for(int i=0; i<20; i++){
		if(arr[i]==AsthmaAns[i]){
			Asthma=true;
			
		}
	}
	if(Asthma==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Asthma  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH \n";
		printmatchingsymptomsSB(arr, AsthmaAns);
		printremainingsymptomsSB(arr, AsthmaAns);
		cout<<"\n \n";
	}
}
void matchAnemia(bool arr[20]){
	 bool AnemiaAns[20]={1,1,0,0,0,0,0,1,0,0,1,1,0,0,0,1,1,0,0,0};

	bool Anemia=false;
	for(int i=0; i<20; i++){
		if(arr[i]==AnemiaAns[i]){
			Anemia=true;
			
		}
	}
	if(Anemia==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH ANEMIA  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsSB(arr, AnemiaAns);
		printremainingsymptomsSB(arr, AnemiaAns);
		cout<<"\n \n";
	}
}
void matchPneumonia0(bool arr[20]){
	 bool PneumoniaAns[20]={1,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,1,1};

	bool Pneumonia=false;
	for(int i=0; i<20; i++){
		if(arr[i]==PneumoniaAns[i]){
			Pneumonia=true;
			
		}
	}
	if(Pneumonia==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Pneumonia  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsSB(arr, PneumoniaAns);
		printremainingsymptomsSB(arr, PneumoniaAns);
		cout<<"\n \n";
	}
}
void matchPleurisy(bool arr[20]){
	 bool PleurisyAns[20]={1,1,0,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,1,0};

	bool Pleurisy=false;
	for(int i=0; i<20; i++){
		if(arr[i]==PleurisyAns[i]){
			Pleurisy=true;
			
		}
	}
	if(Pleurisy==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Pleurisy \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsSB(arr, PleurisyAns);
		printremainingsymptomsSB(arr, PleurisyAns);
		cout<<"\n \n";
	}
}
void matchBronchitis0(bool arr[20]){
	 bool BronchitisAns[20]={1,1,0,0,0,0,1,0,0,0,1,1,0,1,0,0,1,0,0,1};

	bool Bronchitis=false;
	for(int i=0; i<20; i++){
		if(arr[i]==BronchitisAns[i]){
			Bronchitis=true;
			
		}
	}
	if(Bronchitis==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Bronchitis \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsSB(arr, BronchitisAns);
		printremainingsymptomsSB(arr, BronchitisAns);
		cout<<"\n \n";
	}
}
void matchEmphysema0(bool arr[20]){
	 bool EmphysemaAns[20]={0,1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,0};

	bool Emphysema=false;
	for(int i=0; i<20; i++){
		if(arr[i]==EmphysemaAns[i]){
			Emphysema=true;
			
		}
	}
	if(Emphysema==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Emphysema  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsSB(arr, EmphysemaAns);
		printremainingsymptomsSB(arr, EmphysemaAns);
		cout<<"\n \n";
	}
}
void matchPneumothorax(bool arr[20]){
	 bool PneumothoraxAns[20]={1,0,1,1,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0};

	bool Pneumothorax=false;
	for(int i=0; i<20; i++){
		if(arr[i]==PneumothoraxAns[i]){
			Pneumothorax=true;
			
		}
	}
	if(Pneumothorax==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Pneumothorax  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsSB(arr, PneumothoraxAns);
		printremainingsymptomsSB(arr, PneumothoraxAns);
		cout<<"\n \n";
	}
}
void matchCoronaryarterydisease(bool arr[20]){
	 bool CoronaryarterydiseaseAns[20]={1,1,0,0,0,0,1,1,0,0,1,0,0,0,0,0,0,0,0,0};

	bool Coronaryarterydisease=false;
	for(int i=0; i<20; i++){
		if(arr[i]==CoronaryarterydiseaseAns[i]){
			Coronaryarterydisease=true;
			
		}
	}
	if(Coronaryarterydisease==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Coronary artery disease  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsSB(arr, CoronaryarterydiseaseAns);
		printremainingsymptomsSB(arr, CoronaryarterydiseaseAns);
		cout<<"\n \n";
	}
}
void matchInterstitiallungdisease(bool arr[20]){
	 bool InterstitiallungdiseaseAns[20]={1,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0};

	bool Interstitiallungdisease=false;
	for(int i=0; i<20; i++){
		if(arr[i]==InterstitiallungdiseaseAns[i]){
			Interstitiallungdisease=true;
			
		}
	}
	if(Interstitiallungdisease==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Interstitiallungdisease  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsSB(arr, InterstitiallungdiseaseAns);
		printremainingsymptomsSB(arr, InterstitiallungdiseaseAns);
		cout<<"\n \n";
	}
}
void matchHeartfailure(bool arr[20]){
	 bool HeartfailureAns[20]={0,1,0,0,0,0,0,1,0,0,1,1,0,0,1,0,0,1,0,0};

	bool Heartfailure=false;
	for(int i=0; i<20; i++){
		if(arr[i]==HeartfailureAns[i]){
			Heartfailure=true;
			
		}
	}
	if(Heartfailure==true){
		cout<<"A FEW OF YOUR SYMPTOMS MATCH WITH Heart failure  \nTHESE ARE THE SYMPTOMS YOU CHOSE WHICH MATCH  \n";
		printmatchingsymptomsSB(arr, HeartfailureAns);
		printremainingsymptomsSB(arr, HeartfailureAns);
		cout<<"\n \n";
	}
}
void AppointmentUpdates(){
	
	int currentwaitlist=0;
    ifstream appointmentupdates;
    appointmentupdates.open("appointments.txt",ios::in);
    string line;
    time_t currentTime = time(nullptr);

    // Convert time_t to tm structure
    tm* timeinfo = localtime(&currentTime);

    // Extract the hour component and represent it as a floating-point number
    float floatHour = static_cast<float>(timeinfo->tm_hour);
    float startHour=9.0;
    
    while (startHour<floatHour) {
    	        	startHour=startHour+0.5;
               getline(appointmentupdates,line);
		       if(!line.empty()){
		       
			   currentwaitlist++;
        
       
              }
    
}
    appointmentupdates.close();
   // Get the current time
    

    // Convert the current time to a string
    

    // Print the current time
   

    cout<<"Current Waiting List Number Being Seen To:"<<currentwaitlist<<endl;


}
void Appointment(){
	
	int waitlistnumber=0;
	//have option to accept appointment or decline
	cout<<"\t \t \t \t \t APPOINTMENT SCHEDULED"<<endl;
// Get the current time
    time_t currentTime=time(nullptr);

    // Convert the current time to a string
    char* timeString=ctime(&currentTime);

    // Print the current time
        cout<<"Current Time: "<<timeString;
        ofstream appointment;
        appointment.open("appointments.txt",ios::app);
        ifstream appointrecord;
        appointrecord.open("appointments.txt",ios::in);
        string index;
        
        	while(getline(appointrecord,index)){
        		
        		waitlistnumber++;
			}
		appointrecord.close();
        cout<<"Waiting List Number:"<<waitlistnumber;
        //cout accept or decline: if decline close, else wait list++
	    cout<<"enter 1 to accept and 0 to decline"<<endl;
	    bool accept;
	    cin>>accept;
	    if(accept==1){
	    	
            
	    	appointment<<1<<endl;
	    	appointment.close();
	    	cout<<"appointment has been scheduled"<<endl;
	    	cout<<"press any key to exit"<<endl;
	    	
	    	getch();
	    	
		}
		else{
			cout<<"appointment was not scheduled";
			cout<<"press any key to exit"<<endl;
	    	getch();
			
			
		}
}
		
void DiagnosisSection(){
	cout<<"\t \t \t \t SYMPTOM CHECKER"<<endl;
	cout<<"Press 1 for adult symptoms"<<endl;
	cout<<"Press 2 for child symptoms"<<endl;
	bool validattempt=false;
	while(validattempt==false){
	   int SymptomOption;
	   cin>>SymptomOption;
	if(SymptomOption==1){
		cout<<"\t \t \t \t \t ADULT SYMPTOMS"<<endl;
		validattempt=true;
		cout<<"\t \t \t Enter number for which symptom you are experiencing"<<endl;
		int symptomnumber;
		cout<<"1) Abdominal Pain"<<endl;
		cout<<"2) Cough"<<endl;
		cout<<"3) Sore Throat"<<endl;
		cout<<"4) Dizziness"<<endl;
		cout<<"5) Shortness Of Breath"<<endl;
		cout<<"6) Difficulty Swallowing"<<endl;
		cout<<"7) Wheezing"<<endl;
		
		bool symptomvalid=false;
		while(symptomvalid==false){
			cin>>symptomnumber;
			if(symptomvalid<1 && symptomvalid>7){
				cout<<"invalid input, try again"<<endl;
				
			}
			else{
				symptomvalid==true;
				break;
			}
		}
		if(symptomnumber==1){
			bool ans[41];
	cout<<"PAIN IS:"<<endl;
	cout<<"burning:"<<endl;
	cin>>ans[0];
	cout<<"crampy:"<<endl;
	cin>>ans[1];
	cout<<"dull:"<<endl;
	cin>>ans[2];
	cout<<"gnawing:"<<endl;
	cin>>ans[3];
	cout<<"intense:"<<endl;
	cin>>ans[4];
	cout<<"intermittent or episodic:"<<endl;
	cin>>ans[5];
	cout<<"ongoing:"<<endl;
	cin>>ans[6];
	cout<<"sharp:"<<endl;
	cin>>ans[7];
	cout<<"steady:"<<endl;
	cin>>ans[8];
	cout<<"sudden:"<<endl;
	cin>>ans[9];
	cout<<"worsening:"<<endl;
	cin>>ans[10];
	cout<<"PAIN LOCATED IN:"<<endl;
	cout<<"abdomen:"<<endl;
	cin>>ans[11];
	cout<<"lower abdomen:"<<endl;
	cin>>ans[12];
	cout<<"middle abdomen:"<<endl;
	cin>>ans[13];
	cout<<"one or both sides:"<<endl;
	cin>>ans[14];
	cout<<"upper abdomen:"<<endl;
	cin>>ans[15];
	cout<<"TRIGGERED BY:"<<endl;
	cout<<"coughing or other jarring movements:"<<endl;
	cin>>ans[16];
	cout<<"drinking alcohol:"<<endl;
	cin>>ans[17];
	cout<<"eating certain foods:"<<endl;
	cin>>ans[18];
	cout<<"menstrual cycle:"<<endl;
	cin>>ans[19];
	cout<<"stress:"<<endl;
	cin>>ans[20];
	cout<<"RELIEVED BY:"<<endl;
	cout<<"antacids:"<<endl;
	cin>>ans[21];
	cout<<"avoiding certain foods:"<<endl;
	cin>>ans[22];
	cout<<"changing position:"<<endl;
	cin>>ans[23];
	cout<<"drinking more water:"<<endl;
	cin>>ans[24];
	cout<<"eating certain foods:"<<endl;
	cin>>ans[25];
	cout<<"eating more fibre:"<<endl;
	cin>>ans[26];
	cout<<"ACCOMPANIED BY:"<<endl;
	cout<<"abdominal swelling:"<<endl;
	cin>>ans[27];
	cout<<"black or bloody stools:"<<endl;
	cin>>ans[28];
	cout<<"constipation:"<<endl;
	cin>>ans[29];
	cout<<"diarrhea:"<<endl;
	cin>>ans[30];
	cout<<"fever:"<<endl;
	cin>>ans[31];
	cout<<"inability to move bowels:"<<endl;
	cin>>ans[32];
	cout<<"looser watery stools:"<<endl;
	cin>>ans[33];
	cout<<"nasea or vomitting:"<<endl;
	cin>>ans[34];
	cout<<"passing gas:"<<endl;
	cin>>ans[35];
	cout<<"pulsing sensation near navel:"<<endl;
	cin>>ans[36];
	cout<<"rash:"<<endl;
	cin>>ans[37];
	cout<<"stomach growling:"<<endl;
	cin>>ans[38];
	cout<<"unintended weight loss:"<<endl;
	cin>>ans[39];
	cout<<"urgent need to move bowels:"<<endl;
	cin>>ans[40];
	
    system("cls");	
	
   
 
 
   
   matchAbdPainAdultAppendicitis(ans);
   matchAbdPainAdultCrohns(ans);
   matchAbdPainAdultCeliac(ans);
   matchAbdPainAdultIBS(ans);
   matchAbdPainAdultLC(ans);
   matchAbdPainAdultFoodPoison(ans);
   matchAbdPainAdultEndometriosis(ans);
   matchAbdPainAdultKidneyStones(ans);
   matchAbdPainAdultPancreatitis(ans);
   matchAbdPainAdultGallstones(ans);
			
		}
		
		else if(symptomnumber==2){
				bool ans[26];
	cout << "COUGH IS:" << endl;
	cout << "Dry :" << endl;
	cin >> ans[0];
	cout << "producing sputum:" << endl;
	cin >> ans[1];
	cout << "producin plegm:" << endl;
	cin >> ans[2];
	cout << "PROBLEM IS:" << endl;
	cout << "new:" << endl;
	cin >> ans[3];
	cout << "recent:" << endl;
	cin >> ans[4];
	cout << "worsning:" << endl;
	cin >> ans[5];
	cout << "progressing:" << endl;
	cin >> ans[6];
	cout << "ongoing:" << endl;
	cin >> ans[7];
	cout << "recurrent:" << endl;
	cin >> ans[8];
	cout << "TRIGERRED OR WORSENED BY:" << endl;
	cout << "allergens:" << endl;
	cin >> ans[9];
	cout << "irritants:" << endl;
	cin >> ans[10];
	cout << "ACCOMPAINED BY:" << endl;
	cout << "chest pain:" << endl;
	cin >> ans[11];
	cout << "tightness:" << endl;
	cin >> ans[12];
	cout << "chills:" << endl;
	cin >> ans[13];
	cout << "difficult swelling:" << endl;
	cin >> ans[14];
	cout << "painful swelling:" << endl;
	cin >> ans[15];
	cout << "fatigue:" << endl;
	cin >> ans[16];
	cout << "fever:" << endl;
	cin >> ans[17];
	cout << "headache:" << endl;
	cin >> ans[18];
	cout << "soar throat:" << endl;
	cin >> ans[19];
	cout << "sneezing:" << endl;
	cin >> ans[20];
	cout << "shortness of breath:" << endl;
	cin >> ans[21];
	cout << "wheezing:" << endl;
	cin >> ans[22];
	cout << "appetite:" << endl;
	cin >> ans[23];
	cout << "musclaches:" << endl;
	cin >> ans[24];
	cout << "itchy eyes:" << endl;
	cin>>ans[25];
	

	system("cls");





	matchCoughinAdultsLaryngitis(ans);
	matchCoughinAdultsPneumonia(ans);
	matchCoughinAdultsBronchitis(ans);
	CoughinAdultsCommoncold(ans);
	matchCoughinAdultsEmphysema(ans);
	matchCoughinAdultsHayfever(ans);
	CoughinAdultsInfluenza(ans);
	matchCoughinAdultsAcutesinusitis(ans);
	matchCoughinAdultsAsthma(ans);
	matchCoughinAdultsChronicsinusitis(ans);
			
		}
		else if(symptomnumber==3){
				bool ans[18];
	cout << "ACCOMPAINED BY:" << endl;
	cout << "blue coloured skin or lips:" << endl;
	cin >> ans[0];
	cout << "chills or sweating:" << endl;
	cin >> ans[1];
	cout << "cough:" << endl;
	cin >> ans[2];
	cout << "difficult or painful swallowing:" << endl;
	cin >> ans[3];
	cout << "difficult or raspy breathing:" << endl;
	cin >> ans[4];
	cout << "enlarged,tender lymph nodes in neck:" << endl;
	cin >> ans[5];
	cout << "fever:" << endl;
	cin >> ans[6];
	cout << "hedache or facial pain:" << endl;
	cin >> ans[7];
	cout << "heartburn:" << endl;
	cin >> ans[8];
	cout << "hoarse or muffled voice:" << endl;
	cin >> ans[9];
	cout << "muscle aches:" << endl;
	cin >> ans[10];
	cout << "red,swollen tonsils:" << endl;
	cin >> ans[11];
	cout << "runny or stuffy nose:" << endl;
	cin >> ans[12];
	cout << "skin rash:" << endl;
	cin >> ans[13];
	cout << "sneezing:" << endl;
	cin >> ans[14];
	cout << "watery eyes:" << endl;
	cin >> ans[15];
	cout << "white patches or pus on tonsils:" << endl;
	cin >> ans[16];
	cout << "yellow or greenish phlegm or discharge from your nose:" << endl;
	cin >> ans[17];


	system("cls");


	matchTonsillitis(ans);
	matchCommonCold(ans);
	matchInfluenza(ans);
	matchStrepThroat(ans);
	matchMononucleasis(ans);
	matchEpiglottitis(ans);
	matchHayfever(ans);
	matchAcuteSinusitis(ans);
	matchGastroesophagealrefluxdisease(ans);
	matchLaryngitis(ans);
   

		}
		else if(symptomnumber==4){
				bool ans[20];
	cout<<"YOU FEEL:"<<endl;
	cout<<"a spinning sensation:"<<endl;
	cin>>ans[0];
	cout<<"unsteady:"<<endl;
	cin>>ans[1];
	cout<<"lightheaded or faint:"<<endl;
	cin>>ans[2];
	cout<<"Symptoms are :"<<endl;
	cout<<"new or sudden"<<endl;
	cin>>ans[3];
	cout<<"ongoing or recurrent"<<endl;
	cin>>ans[4];
	cout<<"Triggered or worsened by:"<<endl;
	cout<<"Change in head or body position:"<<endl;
	cin>>ans[5];
	cout<<"Accompanied by :"<<endl;
	cout<<"anxiety:"<<endl;
	cin>>ans[6];
	cout<<"Nausea or vomiting:"<<endl;
	cin>>ans[7];
	cout<<"Blurred or double vision"<<endl;
	cin>>ans[8];
	cout<<"numbness or weakness"<<endl;
	cin>>ans[9];
	cout<<"buzzing or ringing in ear"<<endl;
	cin>>ans[10];
	cout<<"pain in neck,jaw,arms etc"<<endl;
	cin>>ans[11];
	cout<<"buzzing or ringing in only one ear"<<endl;
	cin>>ans[12];
	cout<<"rapid or irrapid heartbeat"<<endl;
	cin>>ans[13];
	cout<<"chest pain"<<endl;
	cin>>ans[14];
	cout<<"swere headache:"<<endl;
	cin>>ans[15];
	cout<<"confusion:"<<endl;
	cin>>ans[16];
	cout<<"shortness of breath"<<endl;
	cin>>ans[17];
	cout<<"ear pain"<<endl;
	cin>>ans[18];
	cout<<"slurred speech"<<endl;
	cin>>ans[19];
	
	
    system("cls");	
	
 
 
 
   
   matchStroke(ans);
   matchHeartattack(ans);
   matchMigraine(ans);
   matchEarinfection(ans);
   matchCarbonmonoxidepoisoning(ans);
   matchAcousticneuroma(ans);
			
		}
		else if(symptomnumber==5){
				bool ans[20];
	cout<<"Problem IS:"<<endl;
	cout<<"new or recent:"<<endl;
	cin>>ans[0];
	cout<<"ongoing or recurrent:"<<endl;
	cin>>ans[1];
	cout<<"PRECEDED BY :"<<endl;
	cout<<"trauma or injury:"<<endl;
	cin>>ans[2];
	cout<<"upper respiratory illness:"<<endl;
	cin>>ans[3];
	cout<<"TRIGGERED OR WORSENED BY"<<endl;
	cout<<"allergens or irritants:"<<endl;
	cin>>ans[4];
	cout<<"exposure to cold air:"<<endl;
	cin>>ans[5];
	cout<<"anxiety or stress:"<<endl;
	cin>>ans[6];
	cout<<"Mild to moderate exertion:"<<endl;
	cin>>ans[7];
	cout<<"coughing,sneezing or deep breath:"<<endl;
	cin>>ans[8];
	cout<<"smoking:"<<endl;
	cin>>ans[9];
	cout<<"ACCOMPANIED BY:"<<endl;
	cout<<"chest pain or tightness:"<<endl;
	cin>>ans[10];
	cout<<"irregular or rapid heartbeat:"<<endl;
	cin>>ans[11];
	cout<<"cough that produces blood:"<<endl;
	cin>>ans[12];
	cout<<"nausea:"<<endl;
	cin>>ans[13];
	cout<<"cough that produces sputum:"<<endl;
	cin>>ans[14];
	cout<<"pale or bluish skin:"<<endl;
	cin>>ans[15];
	cout<<"dizziness or fainting:"<<endl;
	cin>>ans[16];
	cout<<"rapid weight gain:"<<endl;
	cin>>ans[17];
	cout<<"dry cough:"<<endl;
	cin>>ans[18];
	cout<<"sweating:"<<endl;
	cin>>ans[19];
	
	
    system("cls");	
	
 
 
 
   
   matchAsthma0(ans);
   matchAnemia(ans);
   matchPneumonia0(ans);
   matchPleurisy(ans);
   matchBronchitis0(ans);
   matchEmphysema0(ans);
   matchPneumothorax(ans);
   matchCoronaryarterydisease(ans);
   matchInterstitiallungdisease(ans);
   matchHeartfailure(ans);
		}
		else if(symptomnumber==6){
				bool ans[20];
	cout << "SWALLOWING:" << endl;
	cout << "hurts:" << endl;
	cin >> ans[0];
	cout << "takes effort:" << endl;
	cin >> ans[1];
	cout << "TRIGGERED OR WPRSENED BY:" << endl;
	cout << "deating certain foods:" << endl;
	cin >> ans[2];
	cout << "ACCOMPAINED BY:" << endl;
	cout << "bad breath:" << endl;
	cin >> ans[3];
	cout << "cough:" << endl;
	cin >> ans[4];
	cout << "difficult breathing:" << endl;
	cin >> ans[5];
	cout << "dry mouth:" << endl;
	cin >> ans[6];
	cout << "earache:" << endl;
	cin >> ans[7];
	cout << "feeling of something stuck in you throat:" << endl;
	cin >> ans[8];
	cout << "heartburn:" << endl;
	cin >> ans[9];
	cout << "hoarse voice difficulty speaking:" << endl;
	cin >> ans[10];
	cout << "jaw pain or stiffness:" << endl;
	cin >> ans[11];
	cout << "loose teeth or poorly fitting dentures:" << endl;
	cin >> ans[12];
	cout << "lump in front of neck:" << endl;
	cin >> ans[13];
	cout << "mouth sores,lumps or pain:" << endl;
	cin >> ans[14];
	cout << "pain in chest or back:" << endl;
	cin >> ans[15];
	cout << "regurgitation of food or sour liquid:" << endl;
	cin >> ans[16];
	cout << "sore throat:" << endl;
	cin >> ans[17];
	cout << "thick saliva:" << endl;
	cin >> ans[18];
	cout << "uninteded weight loss:" << endl;


	system("cls");





	matchGastroesophagealrefluxdisease2(ans);
	matchThroatcancer(ans);
	matchEsophagealcancer(ans);
	matchMouthcancer(ans);
	matchEsophagealspasms(ans);
	matchDrymouth(ans);
			
		}
		else if(symptomnumber==7){
				bool ans[17];
	cout << "WHEEZING IS:" << endl;
	cout << "new or recent:" << endl;
	cin >> ans[0];
	cout << "ongoing or recurrent:" << endl;
	cin >> ans[1];
	cout << "PRECEDED BY:" << endl;
	cout << "upper respiratory illness:" << endl;
	cin >> ans[2];
	cout << "TRIGGERED OR WORSENED:" << endl;
	cout << "allergens or irritants:" << endl;
	cin >> ans[3];
	cout << "exposure to cold air:" << endl;
	cin >> ans[4];
	cout << "mild to moderate exertion:" << endl;
	cin >> ans[5];
	cout << "smoking:" << endl;
	cin >> ans[6];
	cout << "ACCOMPANIED BY:" << endl;
	cout << "blue coloured skin or lips:" << endl;
	cin >> ans[7];
	cout << "chest pain or tightness:" << endl;
	cin >> ans[8];
	cout << "cough that produces sputum:" << endl;
	cin >> ans[9];
	cout << "difficult or painful swallowing:" << endl;
	cin >> ans[10];
	cout << "dry cough:" << endl;
	cin >> ans[11];
	cout << "fatigue or weekness:" << endl;
	cin >> ans[12];
	cout << "fever:" << endl;
	cin >> ans[13];
	cout << "hoarse or muffled voice:" << endl;
	cin >> ans[14];
	cout << "shortness of breath:" << endl;
	cin >> ans[15];
	cout << "sore throat:" << endl;
	cin >> ans[16];



	system("cls");





	matchAsthma(ans);
	matchbronchitis(ans);
	matchEmphysema(ans);
	matchEpiglottis(ans);
			
		}
	}
	else if(SymptomOption==2){
		cout<<"\t \t \t \t \t CHILD SYMPTOMS"<<endl;
		validattempt=true;
		
		cout<<"\t \t \t Enter number for which symptom you are experiencing"<<endl;
		int symptomnumber;
		cout<<"1) Wheezing"<<endl;
		cout<<"2) Fever"<<endl;
		cout<<"3) Diarrhea"<<endl;
		cout<<"4) Nasal Congestion"<<endl;
		cout<<"5) Skin Rashes"<<endl;
		cout<<"6) Nausea or Vomiting"<<endl;
		cout<<"7) Headaches"<<endl;
		
		bool symptomvalid=false;
		while(symptomvalid==false){
			cin>>symptomnumber;
			if(symptomvalid<1 && symptomvalid>7){
				cout<<"invalid input, try again"<<endl;
				
			}
			else{
				symptomvalid==true;
				break;
			}
		}
		if(symptomnumber==1)
		{
				bool ans[20];
	cout<<"WHEEZING IS:"<<endl;
	cout<<"new or recent:"<<endl;
	cin>>ans[0];
	cout<<"ongoing or recuurent:"<<endl;
	cin>>ans[1];
	cout<<"TRIGGERED OR WORSENED BY:"<<endl;
	cout<<"allergens or irritants"<<endl;
	cin>>ans[2];
	cout<<"mild to moderate exertion"<<endl;
	cin>>ans[3];
	cout<<"exposure to cold air"<<endl;
	cin>>ans[4];
	cout<<"RELATED COUGH :"<<endl;
	cout<<"is dry"<<endl;
	cin>>ans[5];
	cout<<"produces phlegm or sputum"<<endl;
	cin>>ans[6];
	cout<<"gasping,harsh or barking"<<endl;
	cin>>ans[7];
	cout<<"ACCOMPANIED BY"<<endl;
	cout<<"Bluish skin on face"<<endl;
	cin>>ans[8];
	cout<<"mild body aches"<<endl;
	cin>>ans[9];
	cout<<"chest pain"<<endl;
	cin>>ans[10];
	cout<<"rapid heartbeat"<<endl;
	cin>>ans[11];
	cout<<"delayed growth"<<endl;
	cin>>ans[12];
	cout<<"rapid or difficult breathing"<<endl;
	cin>>ans[13];
	cout<<"drooling"<<endl;
	cin>>ans[14];
	cout<<"severe respiratory infections"<<endl;
	cin>>ans[15];
	cout<<"enlargement of fingertips"<<endl;
	cin>>ans[16];
	cout<<"runny nose"<<endl;
	cin>>ans[17];
	cout<<"failure to thrive"<<endl;
	cin>>ans[18];
	cout<<"shortness of breath"<<endl;
	cin>>ans[19];
	
	
    system("cls");	
	
 
 
 
   
   matchAsthma1(ans);
   matchBronchiolitis(ans);
   matchHayfever1(ans);
   matchCroup(ans);
   matchCysticfibrosis(ans);
   matchBronchitis(ans);
   matchCommoncold(ans);
		}
	else if(symptomnumber==2)
	{
			bool ans[14];
	cout << "ACCOMPANIED BY" << endl;
	cout << "abdominal pain or cramping" << endl;
	cin >> ans[0];
	cout << "night sweats" << endl;
	cin >> ans[1];
	cout << "bloody urine" << endl;
	cin >> ans[2];
	cout << "rapid heartbeat" << endl;
	cin >> ans[3];
	cout << "bloody stools" << endl;
	cin >> ans[4];
	cout << "rapid of difficult breathing" << endl;
	cin >> ans[5];
	cout << "chest pain" << endl;
	cin >> ans[6];
	cout << "rash" << endl;
	cin >> ans[7];
	cout << "chills" << endl;
	cin >> ans[8];
	cout << "red spots at back of mouth" << endl;
	cin >> ans[9];
	cout << "cough" << endl;
	cin >> ans[10];
	cout << "red swollen tonsils" << endl;
	cin >> ans[11];
	cout << "decreased energy" << endl;
	cin >> ans[12];
	cout << "runny or stuffy nose" << endl;
	cin >> ans[13];

	system("cls");


	matchPneumonia(ans);
	matchBronchiolitis1(ans);
	matchMononucleosis(ans);
	matchInfluenza1(ans);
	matchRoseola(ans);
	matchRotavirus(ans);
	matchCommoncold1(ans);
	}
	else if(symptomnumber==3)
	{
			bool ans[20];
	cout<<"PROBLEM IS:"<<endl;
	cout<<"ongoing:"<<endl;
	cin>>ans[0];
	cout<<"recent:"<<endl;
	cin>>ans[1];
	cout<<"sudden:"<<endl;
	cin>>ans[2];
	cout<<"PRECEDED BY:"<<endl;
	cout<<"eating suspect food:"<<endl;
	cin>>ans[3];
	cout<<"recent antibiotic use:"<<endl;
	cin>>ans[4];
	cout<<"TRIGERRED OR WORSENED BY:"<<endl;
	cout<<"eating certain foods:"<<endl;
	cin>>ans[5];
	cout<<"RELIEVED BY:"<<endl;
	cout<<"avoiding certain foods:"<<endl;
	cin>>ans[6];
	cout<<"ACCOMPANIED BY:"<<endl;
	cout<<"abdominal pain or cramping:"<<endl;
	cin>>ans[7];
	cout<<"bloating or abdominal swlling:"<<endl;
	cin>>ans[8];
	cout<<"bloody stools:"<<endl;
	cin>>ans[9];
	cout<<"decreased energy or fatigue:"<<endl;
	cin>>ans[10];
	cout<<"fever:"<<endl;
	cin>>ans[11];
	cout<<"foul-smelling stools:"<<endl;
	cin>>ans[12];
	cout<<"hallucinations:"<<endl;
	cin>>ans[13];
	cout<<"mucus in stools:"<<endl;
	cin>>ans[14];
	cout<<"muscle or joint aches:"<<endl;
	cin>>ans[15];
	cout<<"nusea or vomiting:"<<endl;
	cin>>ans[16];
	cout<<"passing gas:"<<endl;
	cin>>ans[17];
	cout<<"stomach growling or rumbling:"<<endl;
	cin>>ans[18];
	cout<<"weight loss:"<<endl;
	cin>>ans[19];
	
    system("cls");	
	
 
 
 
   
   matchDiarrheaChildAntibioticAssociated(ans);
   matchDiarrheaChildGiardiaInfection(ans);
   matchDiarrheaChildLactInt(ans);
   matchDiarrheaChildTravelersDiarrhae(ans);
   matchDiarrheaChildVGas(ans);
   matchDiarrheaChildFoodPoison(ans);
   matchDiarrheaChildRotavirus(ans);
   matchDiarrheaChildShigIn(ans);
	}
	else if(symptomnumber==4)
	{
			bool ans[31];
	cout<<"PROBLEM IS:"<<endl;
	cout<<"new or recent:"<<endl;
	cin>>ans[0];
	cout<<"ongoing:"<<endl;
	cin>>ans[1];
	cout<<"recent and worsening:"<<endl;
	cin>>ans[2];
	cout<<"NASAL DISCHARGE IS:"<<endl;
	cout<<"clear or watery:"<<endl;
	cin>>ans[3];
	cout<<"mainly from one side:"<<endl;
	cin>>ans[4];
	cout<<"yellow or greenish:"<<endl;
	cin>>ans[5];
	cout<<"ACCOMPANIED BY:"<<endl;
	cout<<"bad breath:"<<endl;
	cin>>ans[6];
	cout<<"blue-colored skin under the eyes:"<<endl;
	cin>>ans[7];
	cout<<"cough:"<<endl;
	cin>>ans[8];
	cout<<"decreased energy or fatigue:"<<endl;
	cin>>ans[9];
	cout<<"delayed growth:"<<endl;
	cin>>ans[10];
	cout<<"ear pain:"<<endl;
	cin>>ans[11];
	cout<<"enlargement or rounding of fingertips or toes:"<<endl;
	cin>>ans[12];
	cout<<"failure to thrive:"<<endl;
	cin>>ans[13];
	cout<<"fatigue:"<<endl;
	cin>>ans[14];
	cout<<"fever:"<<endl;
	cin>>ans[15];
	cout<<"foul odor or bad breath:"<<endl;
	cin>>ans[16];
	cout<<"foul-smelling stools:"<<endl;
	cin>>ans[17];
	cout<<"headache or facial pain:"<<endl;
	cin>>ans[18];
	cout<<"itchy eyes, nose, mouth or throat:"<<endl;
	cin>>ans[19];
	cout<<"mild body aches:"<<endl;
	cin>>ans[20];
	cout<<"nosebleeds:"<<endl;
	cin>>ans[21];
	cout<<"object in nostril:"<<endl;
	cin>>ans[22];
	cout<<"recurrent, severe respiratory infections:"<<endl;
	cin>>ans[23];
	cout<<"reduced sense of smell or taste:"<<endl;
	cin>>ans[24];
	cout<<"runny nose:"<<endl;
	cin>>ans[25];
	cout<<"sneezing:"<<endl;
	cin>>ans[26];
	cout<<"snoring:"<<endl;
	cin>>ans[27];
	cout<<"sore throat:"<<endl;
	cin>>ans[28];
	cout<<"upper jaw or tooth pain:"<<endl;
	cin>>ans[29];
	cout<<"watery eyes:"<<endl;
	cin>>ans[30];

   system("cls");	
	
 
 
  matchNaCoChildActSinusitis(ans);
  matchNaCoChildChrSinusitis(ans);
  matchNaCoChildComCold(ans);
  matchNaCoHayFever(ans);
  matchNaCoChildCF(ans);
  matchNaCoChildFOITN(ans);
  matchNaCoNARhin(ans);
  matchNaCoChildNP(ans);
  matchNaCoChildDS(ans);
	}
	
	else if(symptomnumber==5)
	{
			bool ans[36];
	cout << "RASH BEST DESCRIBED AS:" << endl;
	cout << "blisters:" << endl;
	cin >> ans[0];
	cout << "itchy:" << endl;
	cin >> ans[1];
	cout << "lacy and slightly raised:" << endl;
	cin >> ans[2];
	cout << "oozing sores that become crusty:" << endl;
	cin >> ans[3];
	cout << "pus filled crusty swellings:" << endl;
	cin >> ans[4];
	cout << "raised red welts:" << endl;
	cin >> ans[5];
	cout << "red or discoloured blotches:" << endl;
	cin >> ans[6];
	cout << "ring shaped:" << endl;
	cin >> ans[7];
	cout << "scaly or flaky:" << endl;
	cin >> ans[8];
	cout << "thick and leathery:" << endl;
	cin >> ans[9];
	cout << "AFFECTS:" << endl;
	cout << "diaper area:" << endl;
	cin >> ans[10];
	cout << "face or neck:" << endl;
	cin >> ans[11];
	cout << "folds of skin:" << endl;
	cin >> ans[12];
	cout << "genital area:" << endl;
	cin >> ans[13];
	cout << "hands or feet:" << endl;
	cin >> ans[14];
	cout << "scalp:" << endl;
	cin >> ans[15];
	cout << "trunk:" << endl;
	cin >> ans[16];
	cout << "PRECEEDED BY:" << endl;
	cout << "eating certain foods:" << endl;
	cin >> ans[17];
	cout << "exposure to allergens or irritants:" << endl;
	cin >> ans[18];
	cout << "exposure to irritating plants:" << endl;
	cin >> ans[19];
	cout << "prolonged exposure to heat:" << endl;
	cin >> ans[20];
	cout << "tick bite or possible exposure to ticks:" << endl;
	cin >> ans[21];
	cout << "ACCOMPANIED BY:" << endl;
	cout << "brittle hair and hairloss:" << endl;
	cin >> ans[22];
	cout << " dandruff" << endl;
	cin >> ans[23];
	cout << "diarrhea:" << endl;
	cin >> ans[24];
	cout << "difficulty breathing:" << endl;
	cin >> ans[25];
	cout << "fever:" << endl;
	cin >> ans[26];
	cout << "hedache:" << endl;
	cin >> ans[27];
	cout << "joint pain:" << endl;
	cin >> ans[28];
	cout << "loss of appetite:" << endl;
	cin >> ans[29];
	cout << "mouth or tongue sores:" << endl;
	cin >> ans[30];
	cout << "muscle aches or pain :" << endl;
	cin >> ans[31];
	cout << "nausea or vomiting:" << endl;
	cin >> ans[32];
	cout << "sore throat:" << endl;
	cin >> ans[33];
	cout << "swelling of lips face or tongue:" << endl;
	cin >> ans[34];

	system("cls");





	matchfoodallergy(ans);
	matchlymedisease(ans);
	matchparvovirusinfection(ans);
	matchringworm(ans);
	matchhandfootmouthdisease(ans);
	matchseborrheicdermatitis(ans);
	matchheatrash(ans);
	matchimpetigo(ans);
	}
	
	else if(symptomnumber==6)
	{
			bool ans[20];
	cout << "TRIGGERED OR WORSENED BY:" << endl;
	cout << "eating certain foods:" << endl;
	cin >> ans[0];
	cout << "travel or motion:" << endl;
	cin >> ans[1];
	cout << "ONSET IS:" << endl;
	cout << "intermittent or episodic:" << endl;
	cin >> ans[2];
	cout << "recent:" << endl;
	cin >> ans[3];
	cout << "sudden:" << endl;
	cin >> ans[4];
	cout << "within the first two months of life:" << endl;
	cin >> ans[5];
	cout << "ACCOMPANIED BY:" << endl;
	cout << "abdominal bkoating or sweating:" << endl;
	cin >> ans[6];
	cout << "abdominal pain,discomfort or cramps:" << endl;
	cin >> ans[7];
	cout << "abdominal pain that is severe and progressive:" << endl;
	cin >> ans[8];
	cout << "constipation:" << endl;
	cin >> ans[9];
	cout << "cough:" << endl;
	cin >> ans[10];
	cout << "diarrhea:" << endl;
	cin >> ans[11];
	cout << "dizziness:" << endl;
	cin >> ans[12];
	cout << "failure to thrive or gain weight:" << endl;
	cin >> ans[13];
	cout << "fever:" << endl;
	cin >> ans[14];
	cout << "fussiness or irritability:" << endl;
	cin >> ans[15];
	cout << "hives or rash:" << endl;
	cin >> ans[16];
	cout << "swelling or tingling of lips,face and tongue:" << endl;
	cin >> ans[17];
	cout << "wet burps or spit up:" << endl;
	cin >> ans[18];
	cout << "wheezing:" << endl;


	system("cls");





	matchFoodallergy(ans);
	matchFoodpoisoning(ans);
	matchAppendicitis(ans);
	matchInfantreflux(ans);
	matchMotionsickness(ans);
	matchViralgastroenteritis(ans);
	}
	
	else if(symptomnumber==7)
	{
			bool ans[31];
	cout<<"PAIN IS:"<<endl;
	cout<<"intense:"<<endl;
	cin>>ans[0];
	cout<<"pressure or squeezing sensation:"<<endl;
	cin>>ans[1];
	cout<<"mild to moderate:"<<endl;
	cin>>ans[2];
	cout<<"stabbing:"<<endl;
	cin>>ans[3];
	cout<<"PAIN LOCATED:"<<endl;
	cout<<"around one eye or radiates from one eye:"<<endl;
	cin>>ans[4];
	cout<<"on one side of head:"<<endl;
	cin>>ans[5];
	cout<<"on both sides of head:"<<endl;
	cin>>ans[6];
	cout<<"ONSET IS:"<<endl;
	cout<<"gradual"<<endl;
	cin>>ans[7];
	cout<<"preceded by visual or other sensory disturbances:"<<endl;
	cin>>ans[8];
	cout<<"preceded by head injury or fall:"<<endl;
	cin>>ans[9];
	cout<<"preceded by sudden:"<<endl;
	cin>>ans[10];
	cout<<"DURATION OF HEADACHE:"<<endl;
	cout<<"is few hours to day"<<endl;
	cin>>ans[11];
	cout<<"is few minutes to hours"<<endl;
	cin>>ans[12];
	cout<<"RECURRENCE OF HEADACHE:"<<endl;
	cout<<"gradually becomes more frequent"<<endl;
	cin>>ans[13];
	cout<<"is often in morning:"<<endl;
	cin>>ans[14];
	cout<<"is daily:"<<endl;
	cin>>ans[15];
	cout<<"is often same time everyday:"<<endl;
	cin>>ans[16];
	cout<<"TRIGGERED OR WORSENED BY :"<<endl;
	cout<<"change in sleep patterns:"<<endl;
	cin>>ans[17];
	cout<<"hormonal changes:"<<endl;
	cin>>ans[18];
	cout<<"clenching:"<<endl;
	cin>>ans[19];
	cout<<"poor posture:"<<endl;
	cin>>ans[20];
	cout<<"RELIEVED BY:"<<endl;
	cout<<"lying down in dark:"<<endl;
	cin>>ans[21];
	cout<<"rest:"<<endl;
	cin>>ans[22];
	cout<<"over the counter pain medication:"<<endl;
	cin>>ans[23];
	cout<<"ACCOMPANIED BY"<<endl;
	cout<<"achy joints or muscles:"<<endl;
	cin>>ans[24];
	cout<<"nausea or vomiting:"<<endl;
	cin>>ans[25];
	cout<<"change in personality:"<<endl;
	cin>>ans[26];
	cout<<"numbness:"<<endl;
	cin>>ans[27];
	cout<<"confusion:"<<endl;
	cin>>ans[28];
	cout<<"restlessness:"<<endl;
	cin>>ans[29];
	cout<<"difficulty in speaking:"<<endl;
	cin>>ans[30];

    system("cls");	
	
 
 
 
   
   matchMigraine1(ans);
   matchEncephlitis(ans);
   matchConcussion(ans);
   matchMeningitis(ans);
   matchBrainTumor(ans);
   matchClusterheadache(ans);
   matchTensionheadache(ans);
   matchTMJDISORDER(ans);
	}
		
	}
	else{
		cout<<"invalid input,try again"<<endl;
		
	}
}
	cout<<"press any key to continue"<<endl;
	getch();
	system("cls");
	cout<<"would you like to schedule an appointment?"<<endl;
	bool appointment;
	cin>>appointment;
	if(appointment==1){
		system("cls");
		Appointment();
	}
	else{
		//continue;
	}

}
int main(){
	//jistrah usernamepassword mein it used to check username availibility, idhar check CNIC taken or not
	//have separate file for registered CNIC then:
	//while inputting data, if CNIC already in file, cout CNIC already registered,try again.
	//remember to close files in places where needed.

	cout<<"\t \t \t \t \t HOSPITAL SYMPTOM CHECKER AND MANAGEMENT SYSTEM"<<endl;
	
	int MenuOption;
	cout<<"Enter 1 to use this system"<<endl;
	cout<<"Enter 2 to check appointment updates"<<endl;
	cout<<"Enter 3 if you are already registered"<<endl;
	/*create password file, ask for CNIC and password, \check if cnic present in cnic file, check if password matches at same number of 
	iterations as CNIC form, if it does, print data by reading record file for certain amount of lines, storing in strings and outputting
	*/ cin>>MenuOption;
	if (MenuOption==1){
		
			PersonalInformationForm();
			system("cls");
			DiagnosisSection();
			system("cls");
			//call function for symptoms
	}
	else if(MenuOption==2){
		//code for appointment times
		
		AppointmentUpdates();
		
	}
		
	else if(MenuOption==3){
	
		     //print personal information form and go to symptom checker
		     /*first ask to enter CNIC number and password, match in files, if matched, for loop  and switch case for 
			 field print rest of data; then move to choosing sympptoms which will be a separate function called.
		    */  string UserCNIC;
		        int RecordNumber=0;
		        bool CNICMatch=false;
		        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		        while(!CNICMatch){
		        	cout<<"Enter CNIC Number"<<endl;
		        	getline(cin,UserCNIC);
		        	ifstream CNICMatching;
                    CNICMatching.open("cnicrecord.txt",ios::in);
                    string CNICinFile;
                    while(getline(CNICMatching,CNICinFile)){
                    	RecordNumber++;
                    	if(CNICinFile==UserCNIC){
                    		CNICMatch=true;
                    		break;
						}
					}
					CNICMatching.close();
					if(!CNICMatch){
						cout<<"CNIC not matched, please enter your CNIC again"<<endl;
						RecordNumber=0;
					}
				}
					
					string PasswordInFile;
					int currentline=1;
					ifstream PasswordMatch;
					PasswordMatch.open("passwords.txt",ios::in);
					while(getline(PasswordMatch, PasswordInFile)&& currentline<RecordNumber){
						++currentline;
					}
					
					PasswordMatch.close();
					string RegPassword;
					int attempts=3;
					do{
						cout<<"Enter Your Password"<<endl;
						getline(cin, RegPassword);
						if(RegPassword==PasswordInFile){
							cout<<"welcome"<<endl;
							//clear screen and call function to print personal information
							PrintForm(RecordNumber);
							//call function for symptoms
							DiagnosisSection();
							break;
						}
						else{
							cout<<"Incorrect password. Attempts remaining:"<<attempts-1<<endl;
							--attempts;
						}
					} while(attempts>0);
					if(attempts==0){
						cout<<"Too many incorrect attempts"<<endl;
						//continue for main loop; to go back to start;
					}
				}	
				
				
	
			
	else{
	
		   cout<<"invalid input, try again"<<endl;
		}
	}
	

