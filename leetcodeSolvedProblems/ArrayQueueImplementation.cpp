#include <iostream>
#include <vector>

using namespace std;

class Patient{
    private:
    static int lastId;
    protected:
    int ID;
    string Name;
    public:
    Patient(string name) : Name(name),ID(++lastId) {}
    
    friend ostream& operator<<(ostream& os, const Patient& patient) {
    os << "ID: " << patient.ID << ", Name: " << patient.Name;
    return os;
}
};

class Queue{
    vector <Patient> dynPatientQueue;
    Patient getInfoOfLastPatient(){
        Patient lastPatient = dynPatientQueue.back();
        return lastPatient;
    }
    public:
    void registerPatient(string name){
        dynPatientQueue.push_back(Patient(name));
    }
    
    void showAllPatients(){
        for(int i = 0; i < dynPatientQueue.size(); i++){
            cout << dynPatientQueue.at(i) << endl;
        }
    }
    void CancelAll(){
        dynPatientQueue.clear();
    }
    bool canDoctorGoHome(){
        bool flag = dynPatientQueue.empty();
        return flag;
    }
    
    void servePatient(){
        dynPatientQueue.erase(dynPatientQueue.begin());
    }
    
};

int Patient::lastId = 0;

int main(){
    Queue patient;
    
    //Entering patients in Queue
    
    patient.registerPatient("Badar");
    patient.registerPatient("Abubaker");
    patient.registerPatient("Anas");
    
    //Displaying all the Patients
    patient.showAllPatients();
    
//checking whether doctor can go home or not

    if(patient.canDoctorGoHome()){
        cout  << "You can go!!!!" << endl;
    }else{
        cout << "Some patients are still left" << endl;
    }
    //first patient is being served
    patient.servePatient();
    //now one patient reduce from the list
    patient.showAllPatients();
    
    patient.CancelAll();
    cout << "Cancelling all appointments!!" << endl;
    
    
    if(patient.canDoctorGoHome()){
        cout  << "You can go!!!!" << endl;
    }else{
        cout << "Some patients are still left" << endl;
    }
}
