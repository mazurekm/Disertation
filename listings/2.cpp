#include<Mlcpack/Algorithms/CCABasedClassifier/CPLST.h>
#include<Mlcpack/Utils/Parser/ArffParser.h>

#include<memory>
#include<iostream>

using namespace Mlcpack::Algorithms;
using namespace Mlcpack::Utils;
using namespace std;
using namespace arma;

int main()
{
    ArffParser parser("iris.arff");
    parser.parse();
    Instances instances = parser.getInstances("iris.xml");
    unique_ptr<IStrategy> cls( new CPLST(instances) );
    cls->learn();
    
    mat inst = {8.0, 2.0};
    cout << cls->classify(inst);

    return 0;
}
