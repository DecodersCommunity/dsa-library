import java.util.*;
public class count_frequency {
    static void countFrequency(int arr[]){
        TreeMap<Integer,Integer>map =new TreeMap<>();
        for(int i:arr){
            if(!map.containsKey(i))map.put(i,1);
            else map.put(i,map.get(i)+1);
        }
        System.out.println("Frequency of each element in the array is :");
        for(int i:map.keySet()){
            System.out.println(i+"-->"+map.get(i));
        }
    }
    public static void main(String[] args) {
        int arr[]={34,1,23,5,2,1,2,23,-12,1,-12,0,32,212,32,32,2,5,5,-56};
        countFrequency(arr);
    }
}