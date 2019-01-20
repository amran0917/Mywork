#include<bits/stdc++.h>
using namespace std;
struct dataStore{
    int a,b,c;
    int id;
   bool test=true;
};
struct test{
    int p,q,r,s;
    int pred_id;
};

struct train{
    int m,n,o,p;
    int pred_id;
    double distance;

};

double avg_accuracy=0.0;
/*void performanceMeasure(int match,int testnum,vector<test>t)
{
      double precision,recall,f1_score,accuracy=0.0;
      int tp=0,tn=0,fp=0,fn=0;

    for(int i=0;i<testnum;i++)
    {
        if(t[i].s==1 &&  t[i].pred_id==1)
        {
            tp++;
        }
        else if(t[i].s==1 &&  t[i].pred_id==2)
        {
            fp++;
        }
        else if(t[i].s==2 &&  t[i].pred_id==1)
        {
            fn++;
        }
        else if(t[i].s==2 &&  t[i].pred_id==2)
        {
            tn++;
        }
    }

    precision = tp/(tp+fp);
    recall= tp/(tp+fn);
    f1_score=(2*(recall * precision)) / (recall + precision);
    accuracy= (tp+tn)/(tp+fp+fn+fn);

    cout<<"Precision: "<<precision<<endl;
    cout<<"Recall: "<<recall<<endl;
    cout<<"F1 score: "<<f1_score<<endl;
    cout<<"Accuracy: "<<accuracy<<endl;

}*/
bool comparison( train &x,  train &y)
{

    return x.distance < y.distance;

}



double distanceCalculate(vector<test>t,vector<train> tr,int countLine,int testnum,int trainNum)
{

      vector<train>cloneTrain(trainNum);
      int match=0;
      int c=0;

      for(int i=0; i<testnum; i++)
      {
               cloneTrain = tr;
          for(int j=0; j<trainNum; j++){

            double d1=t[i].p-tr[j].m;
            double d2=t[i].q-tr[j].n;
            double d3=t[i].r-tr[j].o;
            cloneTrain[j].distance  =sqrt(pow(d1,2)+pow(d2,2)+pow(d3,2));

          }

          sort(cloneTrain.begin(),cloneTrain.end(),comparison);

          int count_1=0,count_2=0;
          int k=3;
          for(int h=0; h<k; h++)
          {
                if(cloneTrain[h].p==1) count_1++;
                else if(cloneTrain[h].p==2) count_2++;
          }

          if(count_1>=1)  t[i].pred_id = 1;
           else t[i].pred_id = 2;

      }


      while(c!=testnum)
      {

            if(t[c].s==t[c].pred_id) match++;
            c++;
      }


   // performanceMeasure(match,testnum,t);
         double precision,recall,f1_score,accuracy=0.0;
      int tp=0,tn=0,fp=0,fn=0;

    for(int i=0;i<testnum;i++)
    {
        if(t[i].s==1 &&  t[i].pred_id==1)
        {
            tp++;
        }
        else if(t[i].s==1 &&  t[i].pred_id==2)
        {
            fp++;
        }
        else if(t[i].s==2 &&  t[i].pred_id==1)
        {
            fn++;
        }
        else if(t[i].s==2 &&  t[i].pred_id==2)
        {
            tn++;
        }
    }

    precision = tp/(tp+fp);
    recall= tp/(tp+fn);
    f1_score=(2*(recall * precision)) / (recall + precision);
   // accuracy= (tp+tn)/(tp+fp+fn+fn);
    accuracy = ((double)match/testnum);


    cout<<"Precision: "<<precision<<endl;
    cout<<"Recall: "<<recall<<endl;
    cout<<"F1 score: "<<f1_score<<endl;
    cout<<"Accuracy: "<<accuracy*100<<"%"<<endl;
    avg_accuracy+=accuracy;


   /* vector<result>rs(trainNum);

     for(int i=0;i<testnum;i++)
    {

        for(int j=0;j<trainNum;j++)
        {

            rs[j].distance= sqrt((t[i].p-tr[j].m)*(t[i].p-tr[j].m)+(t[i].q-tr[j].n)*(t[i].q-tr[j].n)+(t[i].r-tr[j].o)*(t[i].r-tr[j].o));
            rs[j].id=tr[j].p;

        }
         sort(rs.begin(),rs.end(),comparison);

        int k=3;
        int count_1=0,count_2=0;

        for(int u=0;u<k;u++)
        {
           // cout<<rs[u].distance<<" "<<rs[u].id<<endl;
            if(rs[u].id==1) count_1++;
            else if(rs[u].id==2) count_2++;
        }
       // cout<<count_1<<endl;
        if(count_1>=1) tr[i].pred_id=1;
        else if(count_2>=1)tr[i].pred_id=2;

         if(tr[i].pred_id==rs[i].id) match++;

         if(count_1>count_2)
        {
                if(tr[i].p==1) match++;

        }

        else
        {
              if(tr[i].p==2) match++;
        }

        rs.resize(trainNum);
    }

        double accuracy=0.0;
        accuracy =((double)match/testnum);
        avg_accuracy+=accuracy;

        int tp=0,fp=0;
        int tn=0,fn=0;
        double precision,recall,f_score;

      for(int v=0; v<testnum; v++)
      {
        if(t[v].s==1 &&  t[v].pred_id==1) tp++;
        else if(t[v].s==1 && t[v].pred_id==2) fp++;
        else if(t[v].s==2 && t[v].pred_id==1) fn++;
        else if(t[v].s==2 && t[v].pred_id==2) tn++;

      }

      precision = (double)(tp/(tp+fp));
      recall = (double)(tp/(tp+fn));
      f_score = (double)(2*precision*recall)/(precision+recall);


      cout<<"*********************"<<endl;
      cout<<"Precision: " << precision <<endl;
      cout<<"REcall : " << recall<<endl;
      cout<<"F_score: " << f_score<<endl;
      cout<<"Accuracy:  "<<accuracy<<endl;
     */

}


void crossValidation(vector<dataStore>data,int countLine)
{

    int l,x,m;
    int testNum = (countLine/10)+1;
    int trainNum = countLine-testNum;
    vector<test>t(testNum);
    vector<train>tr(trainNum);
    vector<dataStore> newArr(countLine);
    newArr = data;


     for(int i=0;i<10;i++)
    {
         x=0;
        l =countLine;
        for(int j=0;j<testNum;j++)
        {


            srand(3);
            m = rand()%l;


            t[j].p=newArr[m].a;
            t[j].q=newArr[m].b;
            t[j].r=newArr[m].c;
            t[j].s=newArr[m].id;
            // x++;

            newArr[m].test=false;
          //  cout<<"Index "<<m<<endl;
           // cout<<t[j].p<<" "<<t[j].q<<" "<<t[j].r<<" "<<t[j].s<<endl;
            newArr.erase(newArr.begin()+m);
        }
       // cout<<"LLLLLLooooooooooooLLLLLl "<<x<<endl;

        int tt=0;
       for(int k=0;k<trainNum;k++)
       {
           newArr[m].test=true;
           tt++;
            tr[k].m=newArr[k].a;
            tr[k].n=newArr[k].b;
            tr[k].o=newArr[k].c;
            tr[k].p=newArr[k].id;
          //  cout<<tr[k].m<<" "<<tr[k].n<<" "<<tr[k].o<<" "<<tr[k].p<<endl;
       }
     //   cout<<tt<<endl;
        distanceCalculate(t,tr,countLine,testNum,trainNum);
        newArr.resize(countLine);

       newArr=data;


}

    cout<<endl<<"Average Accuracy: "<<(avg_accuracy/10.0)*100<<"%"<<endl;


}

int StringToInteger(string value)
{
    int val;
    istringstream iss(value);
    iss >> val;

    return val;
}


int main()
{
    ifstream ifile;
    string s;
    int countLine=0,take;
    ifile.open("haberman.data");


    vector<dataStore> data(50000);

    if(ifile.is_open())
    {
        while(getline(ifile,s))
        {

            string value;
            istringstream iss(s);

            int k=0;
            while(getline(iss,value,','))
            {
                k++;
                take=StringToInteger(value);
                if(k==1){data[countLine].a=take;}
                else if(k==2){data[countLine].b=take;}
                else if(k==3){data[countLine].c=take;}
                else if(k==4){data[countLine].id=take;}
                data[countLine].test=true;

            }

             countLine++;

        }

        ifile.close();
    }

    data.resize(countLine);

    crossValidation(data,countLine);



    return 0;
}

