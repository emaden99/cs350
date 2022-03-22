#include <stdio.h>
#define SWAP(a,b) { __typeof__(a) temp; temp = a; a = b; b = temp; }

int getLen(char* arr[]) {
    int len = (sizeof(arr));
    return len;
}

void checkPassThreshold(int threshold, char* foods[], int values[]) {
    int count = 0;
    for (int i = 0; i < getLen(foods); i++)
      {
        printf ("%c", '\n');
        if (values[i] >= threshold)
      {
          count += 1;
        printf ("%d  %s", values[i], foods[i]);
      }
        printf ("%c", '\n');
      }
    if(count == 0) {
        printf("%s%c", "You are eating at home/dorm today!", '\n');
    }
}

void getTheTopPoint(char* foods[], int values[]) {
    for (int i = 0; i < getLen(foods); i++) {
        for (int j = i+1; j < getLen(foods); j++) {
           if(values[i] < values[j]) {
               SWAP(values[i],values[j]);
               SWAP(foods[i],foods[j]);
           }
        }
    }
    for (int i = 0; i < getLen(foods); i++)
    {
      printf ("%d  %s%c", values[i], foods[i], '\n');
    }
    printf("You are eating %s today!%c", foods[0], '\n');
}

void firstRound(int threshold, char* foods[], int people) {
    int index;
    int length = getLen(foods);
    int values[length];
    for(int i=0; i< length; i++){
        values[i] = 0;
    }
     for (int person = 0; person < people; person++)
    {
      for (int choice = 0; choice < length;
       choice++)
    {
      printf ("%c", '\n');
      for (int food = 0; food < length;
           food++)
        {
          printf ("%d-%s%c", food + 1, foods[food], '\n');
        }
      printf ("Enter the %d. preference: ", choice + 1);
      scanf ("%d", &index);
      printf ("%d. preference is %s%c", choice + 1, foods[index - 1], '\n');
      values[index - 1] =
        values[index - 1] + length - choice;
    }
    }
    checkPassThreshold(threshold, foods, values);
}

void secondRound(int threshold, char* foods[], int people) {
    int index;
    int length = getLen(foods);
    int values[length];
    for(int i=0; i< length; i++){
        values[i] = 0;
    }
     for (int person = 0; person < people; person++)
    {
      for (int choice = 0; choice < length;
       choice++)
    {
      printf ("%c", '\n');
      for (int food = 0; food < length;
           food++)
        {
          printf ("%d- %s%c", food + 1, foods[food], '\n');
        }
      printf ("Enter the %d. preference: ", choice + 1);
      scanf ("%d", &index);
      printf ("%d. preference is %s%c", choice + 1, foods[index - 1], '\n');
      values[index - 1] =
        values[index - 1] + length - choice;
    }
    }
    getTheTopPoint(foods, values);
}

int main ()
{
  int threshold = 25;
  char *foods[] =
    { "Kebab", "Burger", "Pasta", "Lahmacun", "Salad", "Apple", "Coffee", "Tea" };
  int people = 3;
  secondRound(threshold, foods, people);
  return 0;
}

