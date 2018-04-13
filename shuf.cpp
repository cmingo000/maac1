#include <cstdio>   // printf
#include <cstdlib>  // rand
#include <time.h>   // time
#include <getopt.h> // to parse long arguments.
#include <stdlib.h>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::cin;
using std::cout;
#include <algorithm>
using std::swap;
using std::min;

vector<int> random_number;
vector<string> input_number;
vector<string> string_number;


static const char* usage =
"Usage: %s [OPTIONS]...\n"
"Limited clone of shuf.  Supported options:\n\n"
"   -e,--echo              treat each argument as an input line.\n"
"   -i,--input-range=LO-HI treat each number in [LO..HI] as an input line.\n"
"   -n,--head-count=N      output at most N lines.\n"
"   --help                 show this message and exit.\n";

int main(int argc, char *argv[]) {
    // define long options
    static int echo=0, rlow=0, rhigh=0;
    static size_t count=-1;
    bool userange = false;
    static struct option long_opts[] = {
        {"echo",        no_argument,       0, 'e'},
        {"input-range", required_argument, 0, 'i'},
        {"head-count",  required_argument, 0, 'n'},
        {"help",        no_argument,       0, 'h'},
        {0,0,0,0}
    };
    // process options:
    char c;
    int opt_index = 0;
    while ((c = getopt_long(argc, argv, "ei:n:h", long_opts, &opt_index)) != -1) {
        switch (c) {
            case 'e':
                echo = 1;
                break;
            case 'i':
                if (sscanf(optarg,"%i-%i",&rlow,&rhigh) != 2) {
                    fprintf(stderr, "Format for --input-range is N-M\n");
                    rlow=0; rhigh=-1;
                } else {
                    userange = true;
                }
                break;
            case 'n':
                count = atol(optarg);
                break;
            case 'h':
                printf(usage,argv[0]);
                return 0;
            case '?':
                printf(usage,argv[0]);
                return 1;
        }
    }
    /* NOTE: the system's shuf does not read stdin *and* use -i or -e.
     * Even -i and -e are mutally exclusive... */

    /* TODO: write me... */




if (echo==1){

while (optind < argc){

// This will shuffle the vector of inputs.
input_number.push_back(argv[optind++]);

}

if (input_number.size()>1){ //if there is more than one value that is when it would only shuffle.
srand(time(0));

for (size_t i=0; i<input_number.size();i++){

    swap(input_number[i],input_number[(rand()%(input_number.size()))]);

}
}


if((int)count<0){

    for(size_t i=0;i<input_number.size();i++){
        cout<<input_number[i]<<"\n";

    }
}
else{

    for(size_t i=0; i<count;i++){
    cout<<input_number[i]<<"\n";
    }

}

    }
else if(userange==true){

        if(rlow>rhigh){
        swap(rlow,rhigh);

    }


    for(int i=rlow; i<rhigh+1;i++){
        random_number.push_back(i);


    }



if(random_number.size()!=1){

    srand(time(0));
    for (size_t i=0; i<random_number.size();i++){


    swap(random_number[i],random_number[(rand()%(random_number.size()))]);

}
}



if((int)count<0){

    for(size_t i=0;i<random_number.size();i++){
        cout<<random_number[i]<<"\n";
    }
}

else{

    for(int i=0; i<(int)count;i++){
    cout<<random_number[i]<<"\n";
    }

}

    }
else{

string y;

     while(getline(cin,y)){
string_number.push_back(y);
    }

if(string_number.size()!=1){
    srand(time(0));
    for (size_t i=0; i<string_number.size();i++){

    swap(string_number[i],string_number[(rand()%(string_number.size()))]);

}
}

if((int)count<0){

    for(size_t i=0;i<string_number.size();i++){
        cout<<string_number[i]<<"\n";
    }
}
else{
    for(size_t i=0; i<count;i++){
    cout<<string_number[i]<<"\n";
    }

}


}
return 0;



}


	return 0;
}
