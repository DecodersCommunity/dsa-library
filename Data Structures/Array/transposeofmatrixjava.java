

// contributed by Siddharth chandrakar (siddharthchandrakar007@gmail.com)

// given [1, 2, 3]
//       [ 4, 5, 6]
//       [ 7, 8, 9]

//       convert it to 

//       [1, 4, 7]
//       [2, 5, 8]
//       [3, 6, 9]
// Transpose of a matix.
import java.util.Arrays;
public class transposeofmatrixjava {
    public static void main(String args[]){
        int arr[][]={{1,2,3},{4,5,6},{7,8,9}};

        for(int i=0;i<arr.length;i++){
            for(int j=i;j<arr[0].length;j++){
                int temp=arr[i][j];
                arr[i][j]=arr[j][i];
                arr[j][i]=temp;
            }
        }
        for(int i=0;i<arr.length;i++){
            for(int j=0;j<arr[0].length;j++){
    
                System.out.print(arr[i][j]+" ");
            }
            System.out.println();
        }
        
    }
}

// Now you try to rotate 90 degree of any squre matrix