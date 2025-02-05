#include<iostream> 
#include<algorithm>

using namespace std ;

const int MAX_SIZE = 100;    

template <class T>
class GSSA
{
    public :
        int iNo ; 
        T Arr[MAX_SIZE];      
        T iValue ;
 
        GSSA(int size);       
        GSSA();               
        bool LinearSearch();
        bool BiDirectional(int start , int end );
        bool BinarySearch( int start , int end );  
        void BubbleSort();
        void SelectionSort();
        void InsertionSort();
};
// constructor 
template <class T>
GSSA<T>::GSSA(int size)
{
    if (size > MAX_SIZE) {
        cout << "Size exceeds the maximum limit. Setting size to " << MAX_SIZE << endl;
        iNo = MAX_SIZE;
    } 
    else 
    {
        iNo = size;
    }
}
//Default Constructor
template <class T>
GSSA<T>::GSSA()
{
    iNo = 0 ; 
    iValue = 0 ;
}

template <class T>
bool GSSA<T>::LinearSearch()
{
    int i = 0 ; 
    for( i = 0 ; i < iNo ; i++)
    {
        if( Arr[i] == iValue)
        {
            return true;
        }
    }
    return false ; 
}
template <class T>
bool GSSA<T>::BiDirectional(int start , int end )
{
    while(start <= end)
    {
        if(Arr[start] == iValue || Arr[end] == iValue)
        {
            return true;
        }
        start ++;
        end -- ;
    }
    return false ; 
}
template <class T>
bool GSSA<T>::BinarySearch( int start , int end )
{
    int mid = 0 ; 

    while (start <= end )
    {
        mid = start + (end  -  start )/2;

        if(Arr[mid] == iValue)
        {
            return true;
        }
        else if (Arr[mid] < iValue)
        {
            start = mid + 1;                
        }
        else 
        {
            end = mid  - 1;
        }    
    }
    return false ;        
}
template <class T>
void GSSA<T>::BubbleSort()
{
    int i , j , temp ; 

    for( i = 0 ; i < iNo ; i++)
    {
        for( j = 0 ; j < iNo - 1 ; j++)
        {
            if (Arr[j] > Arr[j+1])
            {
                swap (Arr[j],Arr[j+1]);
            }
        }
    }
}
template <class T>
void GSSA<T>::SelectionSort()
{
    int i , j = 0 ,  temp ; 
    int min_index = 0 ; 

    for ( i = 0 ; i < iNo ; i ++)
    {
        min_index = i ; 

        for ( j = i + 1 ; j < iNo ; j++)
        {
            if(Arr[min_index] > Arr[j])
            {
                min_index = j ;
            }
        }
        swap (Arr[i],Arr[min_index]);
    }
}
template <class T>
void GSSA<T>::InsertionSort()
{
    for (int i = 1; i < iNo; i++)
    {
        T Selected = Arr[i];
        int j = i - 1;
        while (j >= 0 && Arr[j] > Selected)
        {
            Arr[j + 1] = Arr[j];
            j--;
        }
        Arr[j + 1] = Selected;
    }
}

int main()
{ 
    cout<<"-------------------------------------------------\n";
    cout<<"Latest Start this Project!!!\n";
    cout<<"-------------------------------------------------\n";

    int Choice = 0 , iValue ;
    int Menu , iSize ;

    cout<<"Enter the  Size of Array :\n";
    cin>>iSize;

    GSSA<int> obj(iSize);

    cout<<"Enter the Number :\n";
    for(int i = 0 ; i < iSize ; i++)
    {
        cin>> obj.Arr[i];
    }

    cout<<"-------------------------------------------------\n";
    cout<<"Select the Menu...... \n";
    cout<<"-------------------------------------------------\n";
    cout<<"\nMenu:\n";
    while(true)
    {
        cout<<"1.Linear Search\n";
        cout<<"2.BiDirectional Search\n";
        cout<<"3.Binary Search\n";
        cout<<"4.Bubble Sort \n";
        cout<<"5.Selection Sort\n";
        cout<<"6.Insertion Sort\n";
        cout<<"7.Terminate the Project\n";

        cout<<"-----------------------------------------------\n";
        cout<<"Enter the Choice : ";
        cin>>Choice;
        cout<<"------------------------------------------------\n";

        if(Choice == 1)
        {    
            cout<<"Enter the Number which you cant to Search :\n";
            cin>>obj.iValue;

            if(obj.LinearSearch())
            {
                cout<<"The number is present.\n";
            }
            else 
            {
                cout<<"The number which is not present.\n";
            }
        }
        else if(Choice == 2)
        {
            cout<<"Enter the Number which you cant to Search :\n";
            cin>>obj.iValue;

            if(obj.BiDirectional(0, iSize - 1))
            {
                cout<<"The number is present.\n";
            }
            else 
            {
                cout<<"The number which is not present.\n";
            }
        }
        else if(Choice == 3)
        { 
            cout<<"Enter the Number which you cant to Search :\n";
            cin>>obj.iValue;

            if(obj.BinarySearch(0, iSize - 1))
            {
                cout<<"The number is present.\n";
            }
            else 
            {
                cout<<"The number which is not present.\n ";
            }
        }
        else if(Choice == 4)
        {
            obj.BubbleSort();

            cout<<"Element After Sorting :\n";
            for( int i = 0 ; i < iSize ; i++)
            {
                cout << obj.Arr[i] << " ";
            }
            cout << endl;
        }
        else if (Choice == 5)
        {

            obj.SelectionSort();
            cout<<"Element After Sorting :\n";
            for( int i = 0 ; i < iSize ; i++)
            {
                cout<< obj.Arr[i]<<" ";
            }
            cout << endl; 

        }
        else if (Choice == 6)
        {
            obj.InsertionSort();
            cout<<"Element After Sorting :\n";
            for(int i = 0 ; i < iSize ; i++)
            {
                cout<<obj.Arr[i]<<" ";
            }
            cout << endl; 
        }
        else if(Choice == 7)
        {
            cout<<"Thank You for using the Generalized Search and Sorting Algorithm Project!!!!......\n";
            break;
        }
        else 
        {
            cout<<"Sorrry this Position is not Valid!!!! ....\n";
        }
    }
}