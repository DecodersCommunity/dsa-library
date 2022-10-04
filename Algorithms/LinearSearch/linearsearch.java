//Contributed by - Saksham Kankani <superherosaksham@gmail.com>
import java.util.*;
import java.lang.*;
import java.io.*;

class Lsearch
{
  public static void main(String[] args) throws java.lang.Exception
  {
    Scanner sc=new Scanner(System.in);
    System.out.println("Enter length of the array");
    int n=sc.nextInt();
    int positionfound=0;
    int c=0;
    int ar[]=new int[n];
    System.out.println("Fill the array");
    for(int i=0;i<n;i++)
    {
      ar[i]=sc.nextInt();
    }
    System.out.println("Enter the number which is to be searched in the array");
    int target=sc.nextInt();
    for(int j=0;j<n;j++)
    {
      if(ar[j]==target)
      {
        positionfound=j;
        c++;
        break;
      }
    }
    if(c!=0)
    System.out.println("Found at index "+positionfound);
    else
      System.out.println("Target not found");
  }
}

    
