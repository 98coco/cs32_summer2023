//
//  main.cpp
//  CS 32 Project 2
//
//  Created by Coco Li on 7/15/23.
//

#include <iostream>
#include "CricketTeam.h"
#include <cassert>
using namespace std;

int main() {
    CricketTeam mumbaiIndians;
    mumbaiIndians.addCricketer ("Rohit", "Sharma", 36.25);
    mumbaiIndians.addCricketer ("Rohit", "Sharma", 36.25);
    mumbaiIndians.addCricketer ("Suryakumar", "Yadav", 32.75);
    mumbaiIndians.addCricketer ("Suryakumar", "Yadav", 32.75);
    mumbaiIndians.addCricketer ("Jasprit", "Bumrah",29.5);
    mumbaiIndians.addCricketer ("Ishan", "Kishan", 32);

    cerr << "checking original list: " << endl;
    assert(mumbaiIndians.cricketerCount() == 4);
    mumbaiIndians.printCricketers();
    cerr<< endl;
    cerr << "checking back list: " <<endl;
    mumbaiIndians.printBackCricketers();
    cerr << "checking substitute function" << endl;

    mumbaiIndians.substituteCricketer("Rohit", "Sharma", 37);
    mumbaiIndians.substituteCricketer("Ishan", "Kishan", 39);
    assert(mumbaiIndians.cricketerCount() == 4);
    mumbaiIndians.printCricketers();

    cerr << endl;
    cerr<< "checking addOrSubstitute function: " << endl;
    mumbaiIndians.addOrSubstitute("Suryakumar", "Yadav", 67);
    mumbaiIndians.addOrSubstitute("Nehal", "Wadhera", 19);
    mumbaiIndians.addOrSubstitute("Tristan", "Stubbs", 41);
    assert(mumbaiIndians.cricketerCount() == 6);
    mumbaiIndians.printCricketers();

    cerr<<endl;
    cerr << "checking releaseCricketer:  " <<endl;
    mumbaiIndians.releaseCricketer("Jasprit", "Bumrah");
    mumbaiIndians.releaseCricketer("Rohit", "Sharma");
    assert(mumbaiIndians.rosteredOnCricketTeam("Jasprit", "Bumrah") == false);
    assert(mumbaiIndians.rosteredOnCricketTeam("Rohit", "Sharma") == false);
    assert(mumbaiIndians.cricketerCount() == 4);
    mumbaiIndians.printCricketers();
    cerr << endl;

    CricketTeam mumbaiIndians2;

    mumbaiIndians2.addCricketer ("Tristan", "Stubbs", 41);
    mumbaiIndians2.addCricketer ("Nehal", "Wadhera", 19);
    mumbaiIndians2.addCricketer ("Suryakumar", "Yadav", 67);
    mumbaiIndians2.addCricketer ("Ishan", "Kishan", 39);


    cerr << "Checking searchForCricketer: " <<endl;
    CricketType val = 40;
    mumbaiIndians.searchForCricketer("Tristan", "Stubbs",val);
    cerr << val << endl;
    CricketType value = 35;
    mumbaiIndians.searchForCricketer("BAOBAO", "LI", value);
    cerr << value << endl;

    cerr << endl;
    cerr << "check rajas forward: " << endl;

    CricketTeam rajasthanRoyals;
    rajasthanRoyals.addCricketer ("Sanju", "Samson", 11);
    rajasthanRoyals.addCricketer ("Jos", "Buttler", 63);
    rajasthanRoyals.addCricketer ("Yashavi", "Jaiswal", 19);
    rajasthanRoyals.addCricketer ("Shimron", "Hetmeyer", 189);
    rajasthanRoyals.addCricketer ("Trent", "Boult", 18);
    rajasthanRoyals.addCricketer ("Ravichandran", "Ashwin", 99);
    rajasthanRoyals.addCricketer ("Yuzvendra", "Chahal", 3);
    assert(rajasthanRoyals.cricketerCount() == 7);
    assert(rajasthanRoyals.noTeam() == false);

    rajasthanRoyals.printCricketers();
    cerr << endl;

    cerr << "check rajas back" <<endl;
    rajasthanRoyals.printBackCricketers();
    cerr << endl;

    CricketTeam Champs;
    Champs.addCricketer ("Coco", "Li", 36.25);
    Champs.addCricketer ("Ruoyi", "Li", 63);
    Champs.addCricketer ("Yane", "Bai", 19);
    Champs.addCricketer ("Shao Ping", "Li", 189);
    Champs.addCricketer ("Emma", "De Beauckelaer", 18);
    Champs.addCricketer ("Vivienne", "Catarroja", 99);
    Champs.addCricketer ("Danitza", "Montes De Oca", 3);

    cerr << "Champs CricketTeam: " << endl;
    Champs.printCricketers();
    assert(Champs.cricketerCount() == 7);
    assert(Champs.noTeam() == false);

    assert(Champs.releaseCricketer("Emma", "lop") == false);
    assert(Champs.releaseCricketer("Emma", "Danit") == false);
    assert(Champs.rosteredOnCricketTeam("Coco", "Li") == true);
    assert(Champs.rosteredOnCricketTeam("ruoyi", "Li") == false);
    assert(Champs.rosteredOnCricketTeam("emma", "de") == false);
    assert(Champs.rosteredOnCricketTeam("Vivienne", "Catarroja") == true);

    string f = "";
    string l = "";
    CricketType jN = -50000000;

    cerr << endl;
    cerr << "checkTeamCricketer" << endl;
    assert(Champs.checkTeamForCricketer(-1, f, l, jN)== false);
    cerr << f << " " << l << " " << jN << endl;
    assert(Champs.checkTeamForCricketer(0, f, l, jN)== true);
    cerr << f << " " << l << " " << jN << endl;
    assert(Champs.checkTeamForCricketer(1, f, l, jN)== true);
    cerr << f << " " << l << " " << jN << endl;
    assert(Champs.checkTeamForCricketer(2, f, l, jN)== true);
    cerr << f << " " << l << " " << jN << endl;
    assert(Champs.checkTeamForCricketer(3, f, l, jN)== true);
    cerr << f << " " << l << " " << jN << endl;
    assert(Champs.checkTeamForCricketer(4, f, l, jN)== true);
    cerr << f << " " << l << " " << jN << endl;
    assert(Champs.checkTeamForCricketer(5, f, l, jN)== true);
    cerr << f << " " << l << " " << jN << endl;
    assert(Champs.checkTeamForCricketer(6, f, l, jN)== true);
    cerr << f << " " << l << " " << jN << endl;
    cerr << "next should be same values: " << endl;
    assert(Champs.checkTeamForCricketer(7, f, l, jN)== false);
    cerr << f << " " << l << " " << jN << endl;

    Champs.addCricketer("teresa", "penoliar", 9);
    Champs.addCricketer("earl", "bumagat", 30);

    cerr << endl;
    cerr << "updated Champs team:" << endl;
    Champs.printCricketers();
    cerr << endl;


    CricketTeam Empty;
    assert(Empty.cricketerCount() == 0);
    assert(Empty.noTeam() == true);
    Empty.printCricketers();


    // copy constructor
    CricketTeam Heather;
    Heather = rajasthanRoyals;

    Heather.printCricketers();
    assert(Heather.cricketerCount() == 7);

    //assignment operator
    rajasthanRoyals = Empty;
    cerr << endl;
    cerr << "empty circketers: " <<endl;
    rajasthanRoyals.printCricketers();
    assert(rajasthanRoyals.cricketerCount() == 0);
    cerr << endl;

    CricketTeam Pets;
    Pets.addCricketer("BaoBao", "Li", 18);
    Pets.addCricketer("Angel", " ", 25);
    Pets.addCricketer("Bruce", " ", 19);
    Pets.addCricketer("Venus", "C.", 16);
    assert(Pets.cricketerCount() == 4);
    assert(Pets.rosteredOnCricketTeam("angel", " ") == false);
    assert(Pets.rosteredOnCricketTeam("Venus", "C. ") == false); //extra space
    assert(Pets.rosteredOnCricketTeam("Venus", "C.") == true);


    CricketTeam ribet;
    ribet.addCricketer("Izzy Iz Izabela", "tuazon", 25);
    ribet.addCricketer("Katie", "Adamick", 13);
    ribet.addCricketer("Wendy", "Mapaye", 12);
    ribet.addCricketer("Jessa", "Tiu", 98);
    ribet.addCricketer("Chloe", "Agas", 67);
    ribet.addCricketer("Patricia", "De Leon", 8);
    ribet.addCricketer("coco", "li", 28);
    assert(ribet.cricketerCount() == 7);

    assert(ribet.searchForCricketer("teresa", "penoliar", val) == false);
    cout << "search for cricketer:" << val << endl;
    cerr<<endl;

    cerr << "before trade: " << endl;
    cerr << "pets: " << endl;
    Pets.printCricketers();
    cerr << endl;
    cerr << "ribet: " << endl;
    ribet.printCricketers();
    cerr << endl;
    Pets.tradeCricketTeams(ribet);
    cerr << "after trade: " << endl;
    cerr << "pets: " << endl;
    Pets.printCricketers();
    cerr << endl;
    cerr << "ribet: " << endl;
    ribet.printCricketers();
    cerr <<endl;

    string pf,pl;
    CricketType pj;

    cerr << "checkTeamForCricketer" << endl;
    assert(Pets.checkTeamForCricketer(0,pf, pl, pj) == true);
    cerr << pf << " " << pl << " " << pj << endl;
    assert(Pets.checkTeamForCricketer(2,pf, pl, pj) == true);
    cerr << pf << " " << pl << " " << pj << endl;

    cerr<< endl;
    cerr << "reassign Pets with AO and copy construct another CricketTeam to keep the values in the current Pets LL" << endl;
    CricketTeam Pets2 = Pets;
    Pets = ribet;
    cerr << endl;
    cerr << "ribet and pets now have the same list: " << endl;
    cerr << "pets: " << endl;
    Pets.printCricketers();
    cerr << endl;
    cerr << "ribet: " << endl;
    ribet.printCricketers();
    cerr << endl;
    cerr << "reassign ribet to Pets old values using AO" << endl;
    ribet = Pets2;
    ribet.printCricketers();
    cerr << endl;
    cerr << "Pets2 have same list as ribet" << endl;
    Pets2.printCricketers();
    cerr << endl;

    cerr << "Let'sub every value in Pets2" << endl;
    Pets2.substituteCricketer("Izzy Iz Izabela", "tuazon", 65);
    Pets2.substituteCricketer("Katie", "Adamick", 34);
    Pets2.substituteCricketer("Wendy", "Mapaye", 9);
    Pets2.substituteCricketer("Jessa", "Tiu", 89);
    Pets2.substituteCricketer("Chloe", "Agas", 89);
    Pets2.substituteCricketer("Patricia", "De Leon", 87);
    Pets2.substituteCricketer("coco", "li", 41);
    Pets2.printCricketers();
    cerr << endl;

    cerr << "Let's addOrSubstitute: " << endl;
    Pets2.addOrSubstitute("Coco", "Li", 56);
    Pets2.addOrSubstitute("Patricia", "De Leon", 35);
    Pets2.addOrSubstitute("Isabela", "Tuazon", 23);
    assert(Pets2.cricketerCount() == 9);
    cerr << "Pets2 updated: " << endl;
    Pets2.printCricketers();

    CricketTeam testCricketerDelete;

    testCricketerDelete.addCricketer("taylor", "swift", 18);
    testCricketerDelete.addCricketer("ariana", "grande", 28);
    testCricketerDelete.addCricketer("sza", " ", 51);
    testCricketerDelete.addCricketer("bryson", "tiller", 45);

    cerr << endl;
    cerr << "current testCricketerDelete: " << endl;
    testCricketerDelete.printCricketers();
    cerr << endl;

    CricketTeam Empty2, Empty3;

    mergeCricketers(Empty, Empty2, testCricketerDelete);
    cerr << "mergeCricketers, 2 empty list" << endl;
    testCricketerDelete.printCricketers();
    assert(testCricketerDelete.cricketerCount() == 0);
    mergeCricketers(Empty, Empty2, Empty3);
    cerr << endl;
    cerr << endl;
    cerr << "mergeCricketers, all 3 empty" << endl;
    Empty3.printCricketers();
    assert(Empty3.cricketerCount() == 0);
    cerr << endl;


    CricketTeam mergingList;
    mergingList.addCricketer("hello", "im", 24);
    mergingList.addCricketer("SO", "TIRED", 5);
    mergingList.addCricketer(" ", "baooooobaooooo", 24);

    mergeCricketers(Empty, mergingList, mergingList);
    mergingList.printCricketers();
    cerr << endl;

//        CricketTeam mumbaiIndians;
//        mumbaiIndians.addCricketer("Rohit", "Sharma", 36.25);
//        mumbaiIndians.addCricketer("Suryakumar", "Yadav", 32.75);
//        assert(!mumbaiIndians.rosteredOnCricketTeam ("",""));
//        mumbaiIndians.addCricketer("Jasprit", "Bumrah", 29.5);
//        mumbaiIndians.addCricketer("", "", 21.0);
//        mumbaiIndians.addCricketer("Cameron", "Green", 24.0);
//        assert(mumbaiIndians.rosteredOnCricketTeam ("", ""));
//        mumbaiIndians.releaseCricketer("Jasprit", "Bumrah");
//        assert(mumbaiIndians.cricketerCount() == 4
//        && mumbaiIndians.rosteredOnCricketTeam("Rohit", "Sharma")
//        && mumbaiIndians.rosteredOnCricketTeam ("Suryakumar",
//        "Yadav")
//        &  mumbaiIndians.rosteredOnCricketTeam ("Cameron", "Green")
//        && mumbaiIndians.rosteredOnCricketTeam ("", ""));
//
//    cerr << endl;
//    CricketTeam rajasthanRoyals;
//    rajasthanRoyals.addCricketer ("Sanju", "Samson", 11);
//    rajasthanRoyals.addCricketer ("Jos", "Buttler", 63);
//    rajasthanRoyals.addCricketer ("Yashavi", "Jaiswal", 19);
//    rajasthanRoyals.addCricketer ("Shimron", "Hetmeyer", 189);
//    rajasthanRoyals.addCricketer ("Trent", "Boult", 18);
//    rajasthanRoyals.addCricketer ("Ravichandran", "Ashwin", 99);
//    rajasthanRoyals.addCricketer ("Yuzvendra", "Chahal", 3);
//    for (int n = 0; n < rajasthanRoyals.cricketerCount(); n++)
//    {
//    string first;
//    string last;
//    int val;
//    rajasthanRoyals.checkTeamForCricketer (n, first, last,
//    val);
//    cerr << first << " " << last << " " << val << endl;
//    }


    CricketTeam Authors;

    Authors.addCricketer("Ali", "Hazelwood", 12);
    Authors.addCricketer("Taylor", "Jenkins Reid", 14);
    Authors.addCricketer("Jenny", "Han", 15);
    assert(Authors.cricketerCount() == 3);

    Authors.printCricketers();
    cerr << endl;

    CricketTeam Flowers;

    Flowers.addCricketer("White", "Daisies", 12);
    Flowers.addCricketer("Red", "Roses", 16);
    assert(Flowers.cricketerCount() == 2);
    Flowers.printCricketers();

    cerr << endl;
    CricketTeam Animals;

    Animals.addCricketer("brown", "bear", 54);
    Animals.addCricketer("orange", "fish", 67);
    assert(Animals.cricketerCount() == 2);
    Animals.printCricketers();
    cerr << endl;
    cerr << "merged different lists: " <<endl;

    mergeCricketers(Authors, Flowers, Animals);
    Animals.printCricketers();
    cerr << endl;

    cerr << "merged odOne same list odJoined: (print odJoined) " << endl;
    mergeCricketers(Authors, Flowers, Authors);
    Authors.printCricketers();
    cerr << endl;

    cerr << "merged odTwo should be the same:  " << endl;
    Flowers.printCricketers();
    cerr << endl;

    cerr << "one empty list passed (odOne)" << endl;
    mergeCricketers(Flowers,Empty,Pets2);
    Pets2.printCricketers();
    cerr << endl;

    cerr << "one empty list passed (odTwo)" << endl;
    mergeCricketers(Animals,Empty,Pets2);
    Pets2.printCricketers();
    cerr << endl;

    CricketTeam Specs1;
    Specs1.addCricketer("Rahul","Dravid",15);
    Specs1.addCricketer("David","Miller",13);
    Specs1.addCricketer("Rahul","Tewatia",9);
    Specs1.addCricketer("David","Wiese",96);
    checkCricketers("David", "*", Specs1, Empty3);
    cerr << "check Cricketers function: " << endl;
    Empty3.printCricketers();
    cerr << endl;

    CricketTeam westIndians;
    westIndians.addCricketer("Darren","Bravo",46);
    westIndians.addCricketer("Dwayne","Bravo",47);
    westIndians.addCricketer("Kieron","Pollard",55);
    westIndians.addCricketer("Nicolas","Pooran",29);
    checkCricketers("*", "Bravo", westIndians, Empty3);
    cerr << "check Cricketers function for WestIndians same bravo ln : " << endl;
    Empty3.printCricketers();
    cerr << endl;

    checkCricketers("*", "*", westIndians, Empty3);
    cerr << "checkCricketers same everything: wild card edition" << endl;
    Empty3.printCricketers();
//
    CricketTeam mtest1; //merge test --> making sure return true and add everything on the list
    mtest1.addCricketer("Trent", "Boult", 18);
    mtest1.addCricketer("Tim", "David", 8);
    mtest1.addCricketer("Rashid", "Khan", 19);


    CricketTeam mtest2;
    mtest2.addCricketer("Trent", "Boult", 18);
    mtest2.addCricketer("Tim", "Southee", 38);
    mtest2.addCricketer("Kane", "Williamson", 22);

    cerr << endl;
    cerr << "testing merge w specs test cases: (true edition)" << endl;
    mergeCricketers(mtest1, mtest2, Empty3);
    Empty3.printCricketers();
    cerr << endl;
    assert(mergeCricketers(mtest1, mtest2, Empty3) == true); //because same full name have same value

    CricketTeam mtest3;
    mtest3.addCricketer("Quinton","DeCock",12);
    mtest3.addCricketer("Faf","DuPlessis",17);
    mtest3.addCricketer("Kagiso","Rabada",25);

    CricketTeam mtest4;
    mtest4.addCricketer("Faf","DuPlessis",13);
    mtest4.addCricketer("Virat","Kohli",18);

    assert(mergeCricketers(mtest3, mtest4, Empty3) == false); //because same full name have same value
    cerr << "testing merge w specs test cases: (false edition)" << endl;
    mergeCricketers(mtest3, mtest4, Empty3);
    Empty3.printCricketers();
    cerr << endl;

    CricketTeam EMPTY1;
    CricketTeam EMPTY2;
    CricketTeam EMPTY3;
    assert(mergeCricketers(EMPTY1, EMPTY2, EMPTY3) == true); // everything empty
    assert(mergeCricketers(EMPTY1, EMPTY2, mtest4) == true); // 2 things empty last one need to become empty
    mergeCricketers(EMPTY1, EMPTY2, mtest4);
    cerr << "2 LL empty so the odjoined needs to be empty: " << endl;
    mtest4.printCricketers();
    cerr << endl;


    cerr <<endl;
    cerr << "all test past!" << endl;
    return 0;
}

