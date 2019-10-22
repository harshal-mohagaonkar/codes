/*
Follow these steps carefully to execute the code - 
1. Install netbeans IDE 
2. Create Java application project in netbeans
3. Install weka
4. Search the weka folder and add the weka.jar API in netbeans by - Open Project Properties >> Select Libraries >> Select the Add JAR/Folder option on the right >> Navigate to the location of weka.jar >> Add the file
5. Copy the java program
6. Build and clean the project first, and then execute

Ensure that the project name, and the package name in the code is the same. Program filename and public class name should also be the same.
The code has 2 BufferedReader statements to include the training and testing datasets. Ensure that while including the datasets, the location mentioned is correct. 

*/

package mla7;
import weka.core.Instances;
//import weka.classifiers.*;
import weka.classifiers.Evaluation;
import weka.classifiers.bayes.NaiveBayes;
import weka.classifiers.evaluation.*;//Evaluation;
import java.io.BufferedReader;
import java.io.FileReader;
import java.lang.Exception;
//@author bnjagdale
public class Mla7
{
 public Mla7()
 {
try
{
 BufferedReader trainReader =
 new BufferedReader(new FileReader("/home/info06/IDSTr.arff"));
//File with text examples
 BufferedReader classifyReader =
 new BufferedReader(new FileReader("/home/info06/IDSTest.arff"));
//File with text to classify
Instances trainInsts = new Instances(trainReader);
Instances classifyInsts = new Instances(classifyReader);
trainInsts.setClassIndex(trainInsts.numAttributes() - 1);
classifyInsts.setClassIndex(classifyInsts.numAttributes() -1);
NaiveBayes model=new NaiveBayes();
model.buildClassifier(trainInsts);
//System.out.println(model);
Evaluation eTest = new Evaluation(classifyInsts);
eTest.evaluateModel(model, classifyInsts);
String[] cmarray = {"normal","anomaly"};
ConfusionMatrix cm = new ConfusionMatrix(cmarray);
//System.out.println(cm.correct());
for (int i = 0; i < classifyInsts.numInstances(); i++)
{
classifyInsts.instance(i).setClassMissing();
double cls =
 model.classifyInstance(classifyInsts.instance(i));
classifyInsts.instance(i).setClassValue(cls);
}
System.out.println("Error Rate: "+eTest.errorRate()*100);
System.out.println("Pct Correct: "+eTest.pctCorrect());
for (int i=0; i<trainInsts.numClasses(); i++)
 {
System.out.println("Class "+ i);
System.out.println("Precision " +eTest.precision(i));
System.out.println("Recall "+eTest.recall(i));
System.out.println("Area under ROC "+eTest.areaUnderROC(i));
System.out.println();
}
//System.out.println(classifyInsts);
}//Try
catch (Exception o)
{
System.err.println(o.getMessage());
}
}//Mla7 constructor
public static void main(String[] args) {
Mla7 nb = new Mla7();
}
}//Class Mla7