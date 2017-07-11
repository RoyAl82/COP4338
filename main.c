#include <stdlib.h>
#include <stdio.h>
#include "String.h"
#include "globalconst.h"
#include "ArrayList.h"
#include "HashMap.h"

#define NUM_OF_CHARACTERS 4
#define NUM_OF_CHARACTERS_CAT 9
#define NUM_OF_CHARACTERS_N_CMP 6
#define CHARACTER_INDEX 3
#define INDEX_OF_CHARACTER 'd'
#define ARRAYLIST_INDEX_GET 100
#define ARRAYLIST_EXPAND 10000
#define ARRAYLIST_ADDING 1000
#define ARRAYLIST_SET_INDEX 10500



void reverse_C(char s[]);
void intToChar(int n, char s[]);

int String_EqualN(String * lhs, String * rhs,size_t n)
{
    for (int i = 0; i < n; i++)
        if (lhs->str[i] != rhs->str[i])
            return 0;
    
    return 1;
}

int main(int argc, char **argv)
{
    
    String a;
    String b;
    String c;
    String d;
    String e;
    String f;
    String g;
    String h;
    String i;
    String j;
    String k;
    String l;
    String m;
    String n;
    String o;
    String p;
    String q;
    String r;
    String s;
    String t;
    String u;
    String v;
    String w;
    String y;
    String title;
    String title1;
    String aa;
    String bb;
    String cc;
    String dd;
    String ee;
    String ff;
    String gg;
    String hh;
    String ii;
    String jj;
    String kk;
    String ll;
    String mm;
    String nn;
    String oo;
    String pp;
    String qq;
    String rr;
    String ss;
    String tt;
    String uu;
    String vv;
    String ww;
    String yy;
    String zz;
    
    

    String *iix = (String *) malloc(sizeof(String));
    
    String_New(&title, "APPENDIX A(String)");
    
    //Print Title
    printf("\n\n\n\n");
    printf("%40s\n", title.str);
    printf("%40s\n", "------------------");
    //End Title
    
    //String_Copy Function
    printf("%15s\n", "String_Copy");
    printf("%15s\n", "-----------");
    printf("Before Copy:\n");
    printf("------------\n");
    
    String_New(&a, "Star Wars");
    String_New(&b, "A Galaxy Far,Far Away");
    
    size_t hashA = String_GetHashCode(&a);
    size_t hashB = String_GetHashCode(&b);
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("Source       : %21s\t%6zu\t%8zu\n",a.str,a.size,hashA);
    printf("Destinantion : %21s\t%6zu\t%8zu\n\n",b.str,b.size,hashB);
    
    printf("After Copy:\n");
    printf("-----------\n");
    
    String * newB = String_Cpy(&b, &a);
    
    hashA = String_GetHashCode(&a);
    hashB = String_GetHashCode(newB);
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("Source       : %21s\t%6zu\t%8zu\n",a.str,a.size,hashA);
    printf("Destinantion : %21s\t%6zu\t%8zu\n\n",newB->str,newB->size,hashB);
    
    //End String_Copy Function
    
    //String_Equal Function
    printf("Are These Strings Equal?\n");
    printf("------------------------\n");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("Source       : %21s\t%6zu\t%8zu\n",a.str,a.size,hashA);
    printf("Destinantion : %21s\t%6zu\t%8zu\n\n",newB->str,newB->size,hashB);
    

    if (String_Equal(&a,newB))
        printf("Yes, String 1: %2s is equal to String 2: %s\n", a.str, b.str);
    else
        printf("No, String 1: %s is equal to String 2: %s\n", a.str, b.str);

    //End String_Equal Function
    
    //String_nCopy Function
    printf("\n%15s\n", "String_nCopy");
    printf("%15s\n", "------------");
    printf("Before Copying %2d characters:\n", NUM_OF_CHARACTERS);
    printf("------------------------------\n");
    
    
    String_New(&c, "Chewbacca");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("Source       : %21s\t%6zu\t%8zu\n",c.str,c.size,c.hashcode);
    printf("Destinantion : %21s\t%6zu\t%8zu\n\n",b.str,b.size,hashB);
    
    printf("After Copying %2d characters:\n", NUM_OF_CHARACTERS);
    printf("-----------------------------\n");
    
    String * newC = String_nCpy(&b, &c,NUM_OF_CHARACTERS);
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("Source       : %21s\t%6zu\t%8zu\n",c.str,c.size,c.hashcode);
    printf("Destinantion : %21s\t%6zu\t%8zu\n\n",newC->str,newC->size,newC->hashcode);
    
    //End String_nCopy Function
    
    //String_EqualN Fuction
    
    printf("\n%15s\n", "String_EqualN");
    printf("%15s\n", "-------------");
    
    String_New(&d, "Chewbacca");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : %25s\t%6zu\t%8zu\n",d.str,d.size,d.hashcode);
    printf("String 2 : %25s\t%6zu\t%8zu\n\n",newC->str,newC->size,newC->hashcode);
    
    printf("Are these 2 Strings Equal in %2d characters?\n", NUM_OF_CHARACTERS);
    printf("--------------------------------------\n");
    
    if (String_EqualN(&d,newC,NUM_OF_CHARACTERS))
        printf("Yes, String 1: %2s is equal to String 2: %s in the first %d characters.\n", a.str, b.str, NUM_OF_CHARACTERS);
    else
        printf("No, String 1: %2s is equal to String 2: %s in the first %d characters.\n", a.str, b.str, NUM_OF_CHARACTERS);
    
    //End String_EqualN Function
    
    //String_Cat Function
    
    printf("\n%15s\n", "String_Cat");
    printf("%15s\n", "-----------");
    
    printf("Before Cat:\n");
    printf("------------\n");
    
    String_New(&f, "R2-");
    String_New(&e, "D2");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("Source       : %21s\t%6zu\t%8zu\n",e.str,e.size,e.hashcode);
    printf("Destinantion : %21s\t%6zu\t%8zu\n\n",f.str,f.size,f.hashcode);
    
    printf("After Cat:\n");
    printf("-----------\n");
    String * newEF = String_Cat(&f, &e);
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("Source       : %21s\t%6zu\t%8zu\n",e.str,e.size,e.hashcode);
    printf("Destinantion : %21s\t%6zu\t%8zu\n\n",newEF->str,newEF->size,newEF->hashcode);
    
    //End String_Cat Function
    
    
    //String_nCat Function
    
    printf("\n%15s\n", "String_nCat");
    printf("%15s\n", "------------");
    
    printf("Before Cat %d characters:\n", NUM_OF_CHARACTERS_CAT);
    printf("-------------------------\n");
    
    String_New(&g, "Boba ");
    String_New(&h, "Fettus");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("Source       : %21s\t%6zu\t%8zu\n",h.str,h.size,h.hashcode);
    printf("Destinantion : %21s\t%6zu\t%8zu\n\n",g.str,g.size,g.hashcode);
    
    printf("After Cat %d characters:\n", NUM_OF_CHARACTERS_CAT);
    printf("------------------------\n");
    String * newGH = String_nCat(&g, &h, NUM_OF_CHARACTERS_CAT);
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("Source       : %21s\t%6zu\t%8zu\n",h.str,h.size,h.hashcode);
    printf("Destinantion : %21s\t%6zu\t%8zu\n\n",newGH->str,newGH->size,newGH->hashcode);
    
    //End String_nCat Function
    
    //String_Cmp Function
    printf("\n%15s\n", "String_Cmp");
    printf("%15s\n", "------------");
    
    String_New(&i, "Darth Vader");
    String_New(&j, "Darth Maul");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : %25s\t%6zu\t%8zu\n",i.str,i.size,i.hashcode);
    printf("String 2 : %25s\t%6zu\t%8zu\n\n",j.str,j.size,j.hashcode);
    
    printf("Is String 1 greater(1), equal(0), or less(-1) than String 2?\n");
    printf("------------------------------------------------------------\n");
    size_t comp;
    printf("String 1 is %s %s String 2\n", (((comp = String_Cmp(&i, &j)) == 1)? "greater(1)": ((comp != 0)? "less(-1)": "equal(0)")), ((comp != 0) ? "than" : ""));
    
    String_New(&i, "Darth Vader");
    String_New(&j, "Darth Vader");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : %25s\t%6zu\t%8zu\n",i.str,i.size,i.hashcode);
    printf("String 2 : %25s\t%6zu\t%8zu\n\n",j.str,j.size,j.hashcode);
    
    printf("Is String 1 greater(1), equal(0), or less(-1) than String 2?\n");
    printf("------------------------------------------------------------\n");
   
    printf("String 1 is %s %s String 2\n", (((comp = String_Cmp(&i, &j)) == 1)? "greater(1)": ((comp != 0)? "less(-1)": "equal(0)")), (comp != 0) ? ("than") : (""));
    
    String_New(&i, "Gen. Greivous");
    String_New(&j, "Gen. Veers");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : %25s\t%6zu\t%8zu\n",i.str,i.size,i.hashcode);
    printf("String 2 : %25s\t%6zu\t%8zu\n\n",j.str,j.size,j.hashcode);
    
    printf("Is String 1 greater(1), equal(0), or less(-1) than String 2?\n");
    printf("------------------------------------------------------------\n");
   
    printf("String 1 is %s %s String 2\n", (((comp = String_Cmp(&i, &j)) == 1)? "greater(1)": ((comp != 0)? "less(-1)": "equal(0)")), ((comp != 0) ? "than" : ""));
    
    //End String_Cmp Function
    
    //String_nCmp Function
    
    printf("\n%15s\n", "String_nCmp");
    printf("%15s\n", "------------");
    
    String_New(&k, "Gen. Greivous");
    String_New(&l, "Gen. Veers");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : %25s\t%6zu\t%8zu\n",k.str,k.size,k.hashcode);
    printf("String 2 : %25s\t%6zu\t%8zu\n\n",l.str,l.size,l.hashcode);
    
    printf("Is String 1 greater(1), equal(0), or less(-1) than String 2?\n");
    printf("------------------------------------------------------------\n");
    printf("String 1 is %s %s String 2\n", (((comp = String_nCmp(&k, &l,NUM_OF_CHARACTERS_N_CMP)) == 1)? "greater(1)": ((comp != 0)? "less(-1)": "equal(0)")), ((comp != 0) ? "than" : ""));
    
    //End String_nCmp Function
    
    //String_Chr
    printf("\n%15s\n", "String_Chr");
    printf("%15s\n", "-----------");
    
    String_New(&m, "Do or Do not, there is no try");
    
    String * newM = String_Chr(&m, 'h');
    
    printf("Source : %31s\t%6zu\t%8zu\n",m.str,m.size,m.hashcode);
    printf("Output : %31s\t%6zu\t%8zu\n\n",newM->str,newM->size,newM->hashcode);
    
    
    //End String_Chr
    
    //String_cSpn Function
    
    printf("\n%15s\n", "String_cSpn");
    printf("%15s\n", "------------");
    
    String_New(&n, "fcba73");
    String_New(&o, "1234567890");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : %25s\t%6zu\t%8zu\n",n.str,n.size,n.hashcode);
    printf("String 2 : %25s\t%6zu\t%8zu\n\n",o.str,o.size,o.hashcode);
    printf("------------\n");
    printf("Output : %zu\n", String_cSpn(&n,&o));
    
    //End String_cSpn Function
    
    //String_pBrk Function
    printf("\n%15s\n", "String_pBrk");
    printf("%15s\n", "------------");
    
    String_New(&p, "Death Star");
    String_New(&q, "aeiou");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : %25s\t%6zu\t%8zu\n",p.str,p.size,p.hashcode);
    printf("String 2 : %25s\t%6zu\t%8zu\n",q.str,q.size,q.hashcode);
    printf("Output   : %25s\t%6zu\t%8zu\n\n", String_pBrk(&p,&q)->str,String_pBrk(&p,&q)->size,String_pBrk(&p,&q)->hashcode) ;
    
    //End String_pBrk Function
    
    //String_rChr Function
    printf("\n%15s\n", "String_rChr");
    printf("%15s\n", "-----------");
    
    String_New(&m, "Do or Do not, there is no try");
    
    String * newMr = String_rChr(&m, 't');

    printf("Source : %31s\t%6zu\t%8zu\n",m.str,m.size,m.hashcode);
    printf("Output : %31s\t%6zu\t%8zu\n\n",newMr->str,newMr->size,newMr->hashcode);
    
    //End String_rChr Function
    
    //String_Spn Function
    printf("\n%15s\n", "String_Spn");
    printf("%15s\n", "------------");
    
    String_New(&s, "129th");
    String_New(&t, "1234567890");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : %25s\t%6zu\t%8zu\n",s.str,s.size,s.hashcode);
    printf("String 2 : %25s\t%6zu\t%8zu\n",t.str,t.size,t.hashcode);
    size_t stVal = String_spn(&s, &t);
    printf("Output   : %25zu\n\n", stVal);
    
    //End Spring_Spn Function
    
    //String_Str Function
    printf("\n%15s\n", "String_Str");
    printf("%15s\n", "------------");
    
    String_New(&u, "No, I am your mother");
    String_New(&v, "your");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : %25s\t%6zu\t%8zu\n",u.str,u.size,u.hashcode);
    printf("String 2 : %25s\t%6zu\t%8zu\n",v.str,v.size,v.hashcode);
    
    String * newUV = String_Str(&u, &v);
    
    printf("Output   : %25s\t%6zu\t%8zu\n\n", newUV->str,newUV->size,newUV->hashcode) ;
    
    //End String_Str Function
    
    //String_Len
    printf("\n%15s\n", "String_Len");
    printf("%15s\n", "------------");
    
    String_New(&w, "Jabba The Hutt");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : %25s\t%6zu\t%8zu\n",w.str,w.size,w.hashcode);
    
    stVal = String_Len(&w);
    
    printf("Output   : %35zu\n\n", stVal);
    
    //End String_Len
    
    //**************************** APPENDIX B *********************
    String_New(&title1, "APPENDIX B");
    
    //Print Title
    printf("\n\n\n");
    printf("%40s\n", title1.str);
    printf("%40s\n", "-----------");
    //End Title
    
    //String_Trim Function
    printf("\n%15s\n", "String_Trim");
    printf("%15s\n", "------------");
    
    String_New(&aa, "  Clone Troopers  ");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : \t->|%s|<-\t%6zu\t%8zu\n",aa.str,aa.size,aa.hashcode);
    String * newAA = String_Trim(&aa);
    printf("Output   : \t\t->|%s|<-\t%6zu\t%8zu\n\n",newAA->str,newAA->size,newAA->hashcode);
    
    //End String_Trim Function

    //String_LTrim Function
    printf("\n%15s\n", "String_LTrim");
    printf("%15s\n", "------------");
    
    String_New(&bb, "  Luke Skywalker    ");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 :->|%s|<-\t%6zu\t%8zu\n",bb.str,bb.size,bb.hashcode);
    String * newBB = String_LTrim(&bb);
    printf("Output   : \t->|%s|<-\t%6zu\t%8zu\n\n",newBB->str,newBB->size,newBB->hashcode);
    
    //End String_LTrim Function
    
    //String_RTrim Function
    printf("\n%15s\n", "String_RTrim");
    printf("%15s\n", "------------");
    
    String_New(&cc, "   Jabba The Hutt   ");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 :->|%s|<-\t%6zu\t%8zu\n",cc.str,cc.size,cc.hashcode);
    String * newCC = String_RTrim(&cc);
    printf("Output   : \t ->|%s|<-\t%6zu\t%8zu\n\n",newCC->str,newCC->size,newCC->hashcode);
    
    //End String_RTrim Function
    
    //String_GetCharFromIndex Function
    printf("\n%15s\n", "String_GetCharFromIndex");
    printf("%15s\n", "-----------------------");
    
    String_New(&dd, "ABCDE");
    printf("The Index is %d\n", CHARACTER_INDEX);
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : %25s\t%6zu\t%8zu\n",dd.str,dd.size,dd.hashcode);
    size_t newDD = String_GetCharFromIndex(&dd, CHARACTER_INDEX);
    printf("Output   : %25c\n\n",(char)newDD);
    
    //End String_GetCharFromIndex Function
    
    //String_IndexOfChar Function
    printf("\n%15s\n", "String_IndexOfChar");
    printf("%15s\n", "------------------");
    
    String_New(&ee, "abcde");
    printf("The character is %c\n", INDEX_OF_CHARACTER);
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : %25s\t%6zu\t%8zu\n",ee.str,ee.size,ee.hashcode);
    size_t indexEE = String_IndexOfChar(&ee, INDEX_OF_CHARACTER);
    printf("Output   : %25zu\n\n",indexEE);
    
    //End String_IndexOfChar Function
    
    //String_Lower Function
    printf("\n%15s\n", "String_Lower");
    printf("%15s\n", "------------");
    
    String_New(&ff, "ABCDE");
    
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : %25s\t%6zu\t%8zu\n",ff.str,ff.size,ff.hashcode);
    String * newFF = String_Lower(&ff);
    printf("Output   : %25s\t%6zu\t%8zu\n\n",newFF->str,newFF->size,newFF->hashcode);
    
    //End String_Lower Function
    
    //String_Upper Function
    printf("\n%15s\n", "String_Upper");
    printf("%15s\n", "------------");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : %25s\t%6zu\t%8zu\n",ee.str,ee.size,ee.hashcode);
    String * newEE = String_Upper(&ee);
    printf("Output   : %25s\t%6zu\t%8zu\n\n",newEE->str,newEE->size,newEE->hashcode);
    
    //End String_Upper Function
    
    //String_Reverse Function
    printf("\n%15s\n", "String_Reverse");
    printf("%15s\n", "---------------");
    String_New(&hh, "0123456789");
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : %25s\t%6zu\t%8zu\n",hh.str,hh.size,hh.hashcode);
    String * newHH = String_Reverse(&hh);
    printf("Output   : %25s\t%6zu\t%8zu\n\n",newHH->str,newHH->size,newHH->hashcode);
    
    //End String_Reverse Function
    
    //String_WordCount Function
    printf("\n%15s\n", "String_WordCount");
    printf("%15s\n", "----------------");
    String_New(&ii, "Yoda Obi Ani");
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : %25s\t%6zu\t%8zu\n",ii.str,ii.size,ii.hashcode);
    size_t wordCountII = String_WordCount(&ii);
    printf("Output   : %25zu\n\n",wordCountII);
    
    String_Delete(&ii);
    String_New(&ii, "First Homework : 100 points");
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("String 1 : %25s\t%6zu\t%8zu\n",ii.str,ii.size,ii.hashcode);
    wordCountII = String_WordCount(&ii);
    printf("Output   : %25zu\n\n",wordCountII);
    
    //End String_WordCount Function
    
    //**************************** ArrayList *******************************
    
    ArrayList * strListA = (ArrayList *) malloc(sizeof(ArrayList));
    ArrayList * strListB = (ArrayList *) malloc(sizeof(ArrayList));
    
    if (!ArrayList_New(strListA) || !ArrayList_New(strListB))
    {
        printf("Error initializing ArrayLists\nExiting.....\n");
        return -1;
    }
    
    
    for (int i = 0; i < 300; i++){
        String * str = (String *)malloc(sizeof(String));
        String * str2 = (String *)malloc(sizeof(String));
        
        String numStr;
        char num[i + 2];
        intToChar(i, num);
        String_New(&numStr, num);
        
        
        String_New(str,"Programming3 ");
        String_Cat(str,&numStr);
        
        String_New(str2,"Programming4 ");
        String_Cat(str2,&numStr);
        
        ArrayList_Add(strListA,str);
        ArrayList_Add(strListB,str2);
    }
    //ArrayList_Get Function
    printf("\n%15s\n", "ArrayList_Get");
    printf("%15s\n", "----------------");
    printf("The index is %d\n", ARRAYLIST_INDEX_GET);
    String * str1 =  (String *) ArrayList_Get(strListA,ARRAYLIST_INDEX_GET);
    String * str2 =  (String *) ArrayList_Get(strListB,ARRAYLIST_INDEX_GET);
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("ArrayList 1 member : %s\t%6zu\t%8zu\n",str1->str,str1->size,str1->hashcode);
    printf("ArrayList 2 member : %s\t%6zu\t%8zu\n\n",str2->str,str2->size,str2->hashcode);
    
    
    //End ArrayList_Get Function
    
    //ArrayList_Copy Function
    
    printf("\n%15s\n", "ArrayList_Copy");
    printf("%15s\n", "----------------");
    ArrayList_Copy(strListA,strListB);
    printf("The member's index after copy is  %d\n", ARRAYLIST_INDEX_GET);
    str1 =  (String *) ArrayList_Get(strListA,ARRAYLIST_INDEX_GET);
    str2 =  (String *) ArrayList_Get(strListB,ARRAYLIST_INDEX_GET);
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    printf("ArrayList 1 member : %s\t%6zu\t%8zu\n",str1->str,str1->size,str1->hashcode);
    printf("ArrayList 2 member : %s\t%6zu\t%8zu\n\n",str2->str,str2->size,str2->hashcode);

    //End ArrayList_Copy Function
    
    //ArrayList_Clear Function
    printf("\n%15s\n", "ArrayList_Clear");
    printf("%15s\n\n", "----------------");
    printf("Before Clear: \n");
    printf("------------\n");
    printf("%35s\t%10s\n", "Size", "Reserved");
    printf("%35s\t%10s\n", "----", "--------");
    printf("ArrayList 1: %22zu\t%10zu\n",strListA->size,strListA->reserved);
    printf("ArrayList 2: %22zu\t%10zu\n\n",strListB->size,strListB->reserved);
    printf("After Clear: \n");
    printf("------------\n");
    printf("%35s\t%10s\n", "Size", "Reserved");
    printf("%35s\t%10s\n", "----", "--------");
    if(ArrayList_Clear(strListA))
        printf("ArrayList 1: %22zu\t%10zu\n",strListA->size,strListA->reserved);
    else
        printf("ArrayList 1: ERROR Clearing!\n");
    
    if(ArrayList_Clear(strListB))
        printf("ArrayList 2: %22zu\t%10zu\n",strListB->size,strListB->reserved);
    else
        printf("ArrayList 2: ERROR Clearing!\n");
    printf("\n");
    
    //End ArrayList_Clear Function
    
    //ArrayList_ExpandReserved Function
    printf("\n%15s\n", "ArrayList_ExpandReserved");
    printf("%15s\n\n", "-------------------------");
    
    printf("Before Expand: \n");
    printf("------------\n");
    
    printf("%35s\t%10s\n", "Size", "Reserved");
    printf("%35s\t%10s\n", "----", "--------");
    
    printf("ArrayList 1: %22zu\t%10zu\n",strListA->size,strListA->reserved);
    printf("ArrayList 2: %22zu\t%10zu\n\n",strListB->size,strListB->reserved);
    
    printf("After Expand: \n");
    printf("-------------\n");
    printf("%35s\t%10s\n", "Size", "Reserved");
    printf("%35s\t%10s\n", "----", "--------");
    
    if(ArrayList_ExpandReserved(strListA, ARRAYLIST_EXPAND))
        printf("ArrayList 1: %22zu\t%10zu\n",strListA->size,strListA->reserved);
    else
        printf("ArrayList 1: ERROR Expanding!\n");
    
    if(ArrayList_ExpandReserved(strListB, ARRAYLIST_EXPAND))
        printf("ArrayList 2: %22zu\t%10zu\n",strListB->size,strListB->reserved);
    else
        printf("ArrayList 2: ERROR Expanding!\n");
    printf("\n");
    
    
    
    //End ArrayList_ExpandReserved Function
    
    //ArrayList Adding
    printf("\n%15s\n", "ArrayList Adding");
    printf("%15s\n\n", "-----------------");
    
    printf("Before Adding: \n");
    printf("------------\n");
    
    printf("%35s\t%10s\n", "Size", "Reserved");
    printf("%35s\t%10s\n", "----", "--------");
    
    printf("ArrayList 1: %22zu\t%10zu\n",strListA->size,strListA->reserved);
    printf("ArrayList 2: %22zu\t%10zu\n\n",strListB->size,strListB->reserved);
    
    printf("After Adding %d: \n", ARRAYLIST_ADDING);
    printf("-------------\n");
    printf("%35s\t%10s\n", "Size", "Reserved");
    printf("%35s\t%10s\n", "----", "--------");
    
    for (int i = 0; i < ARRAYLIST_ADDING; i++)
    {
        String numStr;
        char num[i + 2];
        intToChar(i, num);
        String_New(&numStr, num);
        
        String * str = (String *)malloc(sizeof(String));
        
        String_New(str,"Programming Class ");
        
        String_Cat(str,&numStr);
        
        ArrayList_Add(strListB,str);
    }
    
    printf("ArrayList 1: %22zu\t%10zu\n",strListA->size,strListA->reserved);
    printf("ArrayList 2: %22zu\t%10zu\n\n",strListB->size,strListB->reserved);
    
    printf("After Adding %d: \n", ARRAYLIST_EXPAND);
    printf("-------------\n");
    printf("%35s\t%10s\n", "Size", "Reserved");
    printf("%35s\t%10s\n", "----", "--------");
    for (int i = 0; i < ARRAYLIST_EXPAND; i++)
    {
        String numStr;
        char num[i + 2];
        intToChar(i, num);
        String_New(&numStr, num);
        
        String * str = (String *)malloc(sizeof(String));
        
        String_New(str,"Programming Class ");
        
        String_Cat(str,&numStr);
        
        ArrayList_Add(strListB,str);
    }
    printf("ArrayList 1: %22zu\t%10zu\n",strListA->size,strListA->reserved);
    printf("ArrayList 2: %22zu\t%10zu\n\n",strListB->size,strListB->reserved);
    
    //End ArrayLIst Adding
    
    //ArrayList_Set Function
    printf("\n%15s\n", "ArrayList_Set");
    printf("%15s\n\n", "------------");
    printf("Before Setting index %d: \n", ARRAYLIST_SET_INDEX);
    printf("------------\n");
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    
    
    String * newStrListB = ArrayList_Get(strListB, ARRAYLIST_SET_INDEX);
    printf("List Item : %24s\t%6zu\t%8zu\n\n",newStrListB->str,
           newStrListB->size,newStrListB->hashcode);
    
    printf("After Setting index %d: \n", ARRAYLIST_SET_INDEX);
    printf("------------\n");
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    
    String * strSet = (String *)malloc(sizeof(String));
    String_New(strSet,"Programming 3 Class");
    ArrayList_Set(strListB,ARRAYLIST_SET_INDEX, strSet);
    
    newStrListB = ArrayList_Get(strListB, ARRAYLIST_SET_INDEX);
    printf("List Item : %24s\t%6zu\t%8zu\n",newStrListB->str,
           newStrListB->size,newStrListB->hashcode);
    
    //End ArrayList_Set Function
    
    //ArrayList_RemoveLast Function
    printf("\n%15s\n", "ArrayList_RemoveLast");
    printf("%15s\n\n", "-------------------");
    
    printf("Before RemoveLast: \n");
    printf("------------------\n");
    
    printf("%35s\t%10s\n", "Size", "Reserved");
    printf("%35s\t%10s\n", "----", "--------");
    
    printf("ArrayList 1: %22zu\t%10zu\n",strListA->size,strListA->reserved);
    printf("ArrayList 2: %22zu\t%10zu\n\n",strListB->size,strListB->reserved);
    
    printf("After RemoveLast: \n");
    printf("-------------\n");
    
    size_t reserved = strListB->reserved;
    
    for (int i = (int)reserved; i >= 0; i--)
    {
        String * s = (String *) ArrayList_Get(strListB,i);
        if (s)
            free(s->str);
            
        ArrayList_RemoveLast(strListB);
    }
    printf("\n");
    printf("%35s\t%10s\n", "Size", "Reserved");
    printf("%35s\t%10s\n", "----", "--------");
    printf("ArrayList 1: %22zu\t%10zu\n",strListA->size,strListA->reserved);
    printf("ArrayList 2: %22zu\t%10zu\n\n",strListB->size,strListB->reserved);
    
        
    //End ArrayList_RemoveLast Function
    
    //ArrayList_Compact Function
    printf("\n%15s\n", "ArrayList_Compact");
    printf("%15s\n\n", "-------------------");
    
    printf("Before Compact: \n");
    printf("------------------\n");
    
    printf("%35s\t%10s\n", "Size", "Reserved");
    printf("%35s\t%10s\n", "----", "--------");
    
    printf("ArrayList 1: %22zu\t%10zu\n",strListA->size,strListA->reserved);
    printf("ArrayList 2: %22zu\t%10zu\n\n",strListB->size,strListB->reserved);
    
    printf("After Compact: \n");
    printf("-------------\n");
    ArrayList_Compact(strListA);
    ArrayList_Compact(strListB);
    
    printf("ArrayList 1: %22zu\t%10zu\n",strListA->size,strListA->reserved);
    printf("ArrayList 2: %22zu\t%10zu\n\n",strListB->size,strListB->reserved);
    
    //End ArrayList_Compact Function
    
//****************************** HashMap *******************************
    //Create HashTable
    
    HashMap myHash;
    
    if(Hash_New(&myHash))
    {
        printf("\n%15s\n", "HashMap New");
        printf("%15s\n\n", "-------------------");
        
        printf("Before Initialization: \n");
        printf("---------------------\n");
        
        printf("%35s\t%10s\n", "currentSize", "tableSize");
        printf("%35s\t%10s\n", "-----------", "---------");
        
        printf("HashMap : %25zu\t%10zu\n",myHash.currentSize, myHash.tableSize);
        
        String numStr;
        
        for(int i = 0; i < 250; i++)
        {
            char num[i + 2];
            
            String * item = (String*) malloc(sizeof(String));
            
            String_New(item, "FIU Computer Science ");
            
            intToChar(i, num);
            String_New(&numStr, num);
            String_Cat(item,&numStr);
            
            Hash_Insert(&myHash, item);
        }
    }
    
    printf("After Initialization: \n");
    printf("---------------------\n");
    
    printf("%35s\t%10s\n", "currentSize", "tableSize");
    printf("%35s\t%10s\n", "-----------", "---------");
    
    printf("HashMap : %25zu\t%10zu\n",myHash.currentSize, myHash.tableSize);
    
    
    //End Create HashTable
    
    //HashMap_Get_Item
    printf("\n%15s\n", "Hash_Get_Item");
    printf("%15s\n\n", "------------");
    
    String * findItem = malloc(sizeof(String));
    
    String_New(findItem, "FIU Computer Science 130");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    
    printf("To Find : %24s\t%6zu\t%8zu\n\n",findItem->str,findItem->size,findItem->hashcode);
    
    String * itemHash = Hash_Get_Item(&myHash, findItem);
    
    printf("Item found : %24s\t%6zu\t%8zu\n\n",itemHash->str,itemHash->size,itemHash->hashcode);
    
    
    //End HashMap_Get_Item
    
    //HashMap Remove
    
    printf("\n%15s\n", "Hash_Remove");
    printf("%15s\n\n", "----------");
    
    printf("%36s\t%s\t%5s\n", "String", "Length", "HashCode");
    printf("%36s\t%s\t%5s\n", "------", "------", "--------");
    
    printf("To remove : %24s\t%6zu\t%8zu\n\n",findItem->str,findItem->size,findItem->hashcode);
    
    if(Hash_Remove(&myHash, findItem) && (itemHash = Hash_Get_Item(&myHash, findItem)))
        printf("didn't remove : %24s\t%6zu\t%8zu\n\n",findItem->str,
               findItem->size,findItem->hashcode);
    else
        printf("Output : Remove successful\n");    
    
    //End HashMap Remove
    
    //Hash_MakeEmpty
    printf("\n%15s\n", "HashMap_MakeEmpty");
    printf("%15s\n\n", "-----------------");
    
//    printf("Before MakeEmpty: \n");
//    printf("---------------------\n");
    
    printf("%35s\t%10s\n", "currentSize", "tableSize");
    printf("%35s\t%10s\n", "-----------", "---------");
    
    printf("Before : %25zu\t%10zu\n",myHash.currentSize, myHash.tableSize);
    if(Hash_MakeEmpty(&myHash))
        printf("After  : %25zu\t%10zu\n",myHash.currentSize, myHash.tableSize);
    else
        printf("HashMap_MakeEmpty Fail.\n");
    
    //End Hash_MakeEmpty

    
    return 0;
}

//itoa: convert n to characters in s
void intToChar(int n, char s[])
{
    int i;
    
    i = 0;
    do
    {
        s[i++] = n % 10 + '0';
        
    } while ((n /= 10) > 0);
    
    s[i] = '\0';
    
    reverse_C(s);
}
void reverse_C(char s[])
{
    int i, length;
    char tmp;
    
    length = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] != '\n')
            length = i + 1;
    }
    
    for (i = 0; i < length / 2; i++)
    {
        tmp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = tmp;
    }
}

