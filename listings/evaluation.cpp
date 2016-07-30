#include<Mlcpack/Utils/Parser/ArffParser.h>
#include<Mlcpack/Algorithms/Evaluation/MethodEvaluator.h>

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
    
    MethodEvaluator evaluator(instances);
    evaluator.evaluate("CPLST");
    std::cout << evaluator.getHammingLoss() << std::endl;

    return 0;
}
