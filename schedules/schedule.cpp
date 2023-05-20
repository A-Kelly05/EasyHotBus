#include<iostream>
#include<string>
#include<vector>

struct Schedulehotbus{
    /*horarioId
      busId
      origen
      destino
      hora de origen
      hora de destino*/
    std::string busName;
    std::string destination;
    std::vector<std::string> departureTime;
};

void hotBusSchedule(const std::vector<Schedulehotbus>$schedule){
    std::cout << "Horario de los buses:\n";
    for (const auto& bus : $schedule){
        std::cout << "Bus: " << bus.busName << "\n";
        std::cout << "Destino: " << bus.destination << "\n";
        std::cout << "Salidas: ";
        for (const auto& time : bus.departureTime){
            std::cout << time <<" ";
        }
        std::cout << "\n-------------------------\n";
    }
}

int main(){
    std::vector<Schedulehotbus> Schedulehotbus;
    
    // Horario del Bus David #2
    Schedulehotbus.push_back({"David #2", "Managua", {"8:30 AM","2:00 PM","6:20 PM"}});
    Schedulehotbus.push_back({"David #2", "Nagarote", {"6:40 AM","11:30 AM","4:30 PM"}});

    // Horario del Bus David #3
    Schedulehotbus.push_back({"David #3", "Managua", {"9:00 AM","2:30 PM","6:40 PM"}});
    Schedulehotbus.push_back({"David #3", "Nagarote", {"7:00 AM","12:00 PM","5:00 PM"}});

    // Horario del Bus David #4
    Schedulehotbus.push_back({"David #4", "Managua", {"10:20 AM","5:15 PM","No hay"}});
    Schedulehotbus.push_back({"David #4", "Nagarote", {"6:30 AM","12:10 PM","No hay"}});

    std::cout << "horarios de los buses de Nagarote a Managua:\n";
    for (const auto& bus : Schedulehotbus){
        if (bus.destination == "Managua"){
            std::cout << "Bus : " << bus.busName << "\n";
            std::cout << "Salidas: ";
            for (const auto& time : bus.departureTime){
                std::cout << time << " ";
            }
            std::cout << "\n";
        }
        
    }
    std::cout << "------------------------\n";


    std::cout << "Horarios de los buses de Managua a Nagarote\n";
    for (const auto& bus : Schedulehotbus){
        if (bus.destination == "Nagarote"){
            std::cout << "Bus: " << bus.busName << "\n";
            std::cout << "Salidas: ";
            for (const auto& time : bus.departureTime){
                std::cout << time << " ";
            }
            std::cout << "\n";
            
        }
        
    }
    std::cout << "-------------------------------\n";

    return 0;
    
    
}   
