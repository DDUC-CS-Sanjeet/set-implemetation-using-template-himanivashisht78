#include<iostream>
#include<math.h>
#include<string.h>
#include<ctype.h>
using namespace std;

template <class T>
class MySet
{
	private:
    T *set;
    int cardinality;
    public:
    MySet(int n)
    {
        cardinality=n;
        set=new T[cardinality];
    }
    void input(T t)
    {
        for(int k=0;k<cardinality;k++)
        {
            	cin>>set[k];
        }
      duplicate_free();
    }
     void output()
    {
    	cout<<"{ ";
        for(int i=0;i<cardinality;i++)
        {
        	if(i==cardinality-1)
        	{
        		cout<<set[i];
			}
        	else
            {
            	cout<<set[i]<<", ";
			}
           
            
        }
        cout<<"\b}"<<endl;
        givecardinality();
    }

    void duplicate_free()
    {
        for(int i=0;i<cardinality;i++)
        {
            for(int j=i+1;j<cardinality;)
            {
                if(set[i]==set[j])
                {
                    set[i]=set[j];
                    for(int k=j;k<cardinality-1;k++)
                    {
                        set[k]=set[k+1];
                    }
                    --cardinality;
                }
                else
                {
                    j++;
                }
                

            }
            
        }
    }
    MySet operator + (const MySet& M)
    {
        MySet<T>temp(cardinality+M.cardinality);
        for(int i=0,j=0;i<(cardinality+M.cardinality);i++)
        {
            if (i<cardinality)
            {
                temp.set[i]=set[i];
            }
            else
            {
                temp.set[i]=M.set[j];
                j++;
            }
            
        }
        temp.duplicate_free();
        return temp;
        
    }
    MySet operator * (const MySet& M1)
    {
      
        int k=0;
        for(int i=0;i<cardinality;i++)
        {
        	for(int j=0;j<M1.cardinality;j++)
        	{
        		if(set[i]==M1.set[j])
        		{
        			k++;
				}
			}
		}
		int p=0;
		MySet<T> temp1(k);
		 for(int i=0;i<cardinality;i++)
        {
        	for(int j=0;j<M1.cardinality;j++)
        	{
        		if(set[i]==M1.set[j])
        		{
        			temp1.set[p]=set[i];
        			p++;
				}
			}
		}
		temp1.duplicate_free();
		return temp1;
    }
    MySet operator - (const MySet& M2)
    {
        MySet<T> temp2(cardinality);
        for(int i=0;i<cardinality;i++)
        {
            temp2.set[i]=set[i];
        }
        MySet<T> Diff=temp2*M2;
        for(int i=0;i<temp2.cardinality;i++)
        {
            for(int j=0;j<Diff.cardinality;j++)
            {
                if(temp2.set[i]==Diff.set[j])
                {
                    for(int k=i;k<temp2.cardinality-1;k++)
                    {
                        temp2.set[k]=temp2.set[k+1];
                    }
                    temp2.cardinality--;

                }
            }
            
        }
        temp2.duplicate_free();
        return temp2;

    }
     MySet operator ^ (MySet M3)
    {
        MySet<T> temp3(cardinality);
        for(int i=0;i<cardinality;i++)
        {
            temp3.set[i]=set[i];
        }
        MySet<T> Diff1=temp3*M3;
        MySet<T> Union1=temp3+M3;
        for(int i=0;i<Union1.cardinality;i++)
        {
            for(int j=0;j<Diff1.cardinality;j++)
            {
                if(Union1.set[i]==Diff1.set[j])
                {
                    for(int k=i;k<Union1.cardinality-1;k++)
                    {
                        Union1.set[k]=Union1.set[k+1];
                    }
                    Union1.cardinality--;

                }
            }
            
        }
        Union1.duplicate_free();
        return Union1;

    }
    
    bool operator == (const MySet<T>& M5)
    {
    	int flag=0;
    	if(cardinality>=M5.cardinality)
    	{
    	    for(int i=0;i<cardinality;i++)
        	{
        		for(int j=0;j<cardinality;j++)
                {
                	if(set[i]==M5.set[j])
            		{
             		   	flag =1;
             		   	break;
            		}
				}
            		
        	}
		}
		else
		{
		    for(int i=0;i<M5.cardinality;i++)
        	{
        		for(int i=0;i<M5.cardinality;i++)
          	    	if(set[i]!=M5.set[i])
          	   		{
            	   		 flag=1;
            	   		 break;
            		}
      		}
		}
      if(flag)
      {
      	 return true;
	  }
	  else{
	  	 return false;
	  }
       
    }
    MySet<T>& operator =(const MySet<T>& M4)
    {
        for(int i=0;i<cardinality;i++)
        {
            set[i]=M4.set[i];
        }
        return *this;
    }
    void givecardinality()
    {
        cout<<"The cardinality of the set is: "<<cardinality<<endl;
    }
    
    void power_set()
    {
        int size=pow(2,cardinality);
        cout<<"{ ";
        for(int i=0;i<size;i++)
        {
            cout<<"{ ";
            for(int j=0;j<cardinality;j++)
            {

                if(i&(1<<j))
                {
                     cout<<set[j]<<", ";
                }

            }
            if(i==size-1)
			{
				 cout<<"\b\b },"; 
		    }   
			else
			{
				cout<<"\b\b }, "; 
			}    
        }
         cout<<"\b }";    
    }
   
      

};

template<typename T>
void setoperation(T t)
{
    int n1,n2;
    char choose;
    

        cout<<"Enter the cardinality of first set: ";
        cin>>n1;
        MySet<T> S1(n1);
        cout<<"\nEnter the cardinality of second set: ";
        cin>>n2;
        MySet<T> S2(n2);
        cout<<"\n\nEnter the elements of the first set: ";
        S1.input(t);
        cout<<"\nEnter the elements of the second set: ";
        S2.input(t);
        int choice;
     do{
        cout<<"\nEnter your choice: \n";
        cout<<"1. Intersection of Two sets\n";
        cout<<"2. Union of Two sets\n";
        cout<<"3. Difference of the Two sets(Enter the biggest set first)\n";
        cout<<"4. Symmetric Difference of Two sets\n";
        cout<<"5. Checking equality of Two sets\n";
        cout<<"6. Power sets of the both sets\n";
        cout<<"7. Implementation of assignment operator \n";
        cout<<"Your choice is: ";
        cin >>choice;
        switch(choice)
        {
            case 1:
            {
            	MySet<T> S3(S1*S2);
            	S3.output();
                break;
            }
            case 2:
            {
            	MySet<T> S3=S1+S2;
            	S3.output();
                break;
            }
            case 3:
            {
            	MySet<T> S4=S2-S1;
            	MySet<T> S3=S1-S2;
            	cout<<"The difference of second set from first is: ";
            	S3.output();
            	cout<<"The difference of first set from second is: ";
            	S4.output();
                break;
            }
            case 4:
            {
            	MySet<T> S3=S1^S2;
            	S3.output();
                break;
            }
            case 5:
            {
            	if(S1==S2)
            	{
            		cout<<"The entered sets are equal\n";
				}
				else
				{
					cout<<"The entered sets are not equal\n";
				}
                break;
            }
            case 6:
           	{  cout<<"\n\nThe power set of the first set ";
			   cout<<" is: \n";
			   S1.power_set();
			   cout<<"\n\nThe power set of the second set ";
			   cout<<" is: \n";
			   S2.power_set(); 	
			   break;	
			}
            case 7:
            {
            	cout<<"The assignment of the second set to another  "<<endl;
            	MySet<T> S3(n2);
            	S3=S2;
            	S3.output();
                break;
            }
            default:
            {
            	cout<<"Invalid\n";
            }
        }
        cout<<"Do you want to continue(Y/N):";
        cin>>choose;
    }while(choose=='Y'||choose=='y');
}





int main()
{
   char check;
   string S="Gaurav";
   cout<<"On which type you want to operate on:\n";
   cout<<"A. char \nB. int \nC. double \nD. String\n Your choice is: ";
   cin>>check;
   switch (toupper(check))
   {
        case 'A':
        {
            setoperation('a');
            break;
        }
        case 'B':
        {
            setoperation(1);
            break;
        }
        case 'C':
        {
            setoperation(1.0);
            break;
        }
        case 'D':
        {
            setoperation(S);
        }
        default:
        {
            cout<<"You entered an invalid choice\n";
        }
   }
    return 0;
}

template class MySet<char>;
template class MySet<int>;
template class MySet<double>;
template class MySet<string>;
