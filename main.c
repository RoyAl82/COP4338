#include <stdlib.h>
#include <stdio.h>
#include "String.h"
#include "globalconst.h"
#include "ArrayList.h"


int String_EqualN(String * lhs, String * rhs,size_t n)
{
    for (int i = 0; i < n; i++)
        if (lhs->str[i] != rhs->str[i])
            return 0;
    
    return 1;
}

int main(int argc, char **argv)
{
    String *a = (String *) malloc(sizeof (String));
    String *b = (String *) malloc(sizeof (String));
    String *c = (String *) malloc(sizeof (String));
    String *d = (String *) malloc(sizeof (String));
    String *e = (String *) malloc(sizeof(String));
    String *f = (String *) malloc(sizeof(String));
    String *g = (String *) malloc(sizeof(String));
    String *h = (String *) malloc(sizeof(String));
    String *i = (String *) malloc(sizeof(String));
    String *j = (String *) malloc(sizeof(String));
    String *k = (String *) malloc(sizeof(String));
    String *l = (String *) malloc(sizeof(String));
    String *m = (String *) malloc(sizeof(String));
    String *n = (String *) malloc(sizeof(String));
    String *o = (String *) malloc(sizeof(String));
    String *p = (String *) malloc(sizeof(String));
    String *q = (String *) malloc(sizeof(String));
    String *r = (String *) malloc(sizeof(String));
    String *s = (String *) malloc(sizeof(String));
    String *t = (String *) malloc(sizeof(String));
    String *u = (String *) malloc(sizeof(String));
    String *v = (String *) malloc(sizeof(String));
    
    String *aa = (String *) malloc(sizeof(String));
    String *bb = (String *) malloc(sizeof(String));
    String *cc = (String *) malloc(sizeof(String));
    String *dd = (String *) malloc(sizeof(String));
    String *ee = (String *) malloc(sizeof(String));
    String *ff = (String *) malloc(sizeof(String));
    String *gg = (String *) malloc(sizeof(String));
    String *hh = (String *) malloc(sizeof(String));
    String *ii = (String *) malloc(sizeof(String));
    String *iix = (String *) malloc(sizeof(String));
    
    //Appendix A
    printf("\n\n\n\n\n\n");
    printf("\t\t\t\t\t\tAPPENDIX A\n");
    
    //String_Copy                                                                                                           Done
    String_New(a, "Star Wars");
    String_New(b, "");
    size_t hash0 = String_GetHashCode(b);
    printf("String_Copy: \n%s\n%s\n", a->str, b->str);
    String * bnew =String_Cpy(b, a);
    printf("%s\n", bnew->str);
    printf("Old Hash: %zu\nNew Hash: %zu\n\n", hash0, String_GetHashCode(b));
    printf("hash a: %zu\nhash b: %zu\nhash bnew: %zu\n",String_GetHashCode(a), String_GetHashCode(b), String_GetHashCode(bnew));
    if (String_Equal(a,bnew))
        printf("====>String_Copy a,b are equal\n");
    else
        printf("====>String_Copy a,b are NOT equal\n");
    
    
    if (String_GetHashCode(a) == String_GetHashCode(bnew))
        printf("====>HashCode a,b equal\n");
    else
        printf("====>HashCode a,b NOT equal\n");
    
    //free(bnew);
    
    //String_nCopy                                                                                                          Done
    String_New(c, "Chewbacca");
    String_New(d, "");
    size_t hash1 = String_GetHashCode(d);
    printf("String_nCopy: \n%s\n%s\n", c->str, d->str);
    String * dnew =String_nCpy(d,c,4);
    printf("%s\n", dnew->str);
    printf("Old Hash: %zu\nNew Hash: %zu\n\n", hash1, String_GetHashCode(d));
    
    String ncp;
    String_New(&ncp,"Chew");
    if (String_EqualN(dnew,&ncp,4))
        printf("====>String_nCopy works\n");
    else
        printf("====>String_Copy does NOT work\n");
    
    //free(dnew);
    //String_Cat                                                                                                            Done
    String_New(e, "R2-");
    String_New(f, "D2");
    size_t hash2 = String_GetHashCode(e);
    String * efnew = String_Cat(e, f);
    printf("String_Cat: \n%s\n%s\n%s\n", e->str, f->str, efnew->str);
    printf("Old Hash: %zu\nNew Hash: %zu\n\n", hash2, String_GetHashCode(e));
    
    String r2d2;
    String_New(&r2d2,"R2-D2");
    if (String_Equal(efnew,&r2d2))
        printf("====>String_Cat works\n");
    else
        printf("====>String_Cat does NOT work\n");
    
    free(efnew);
    
    
    //String_nCat                                                                                                           Done
    String_New(g, "Boba ");
    String_New(h, "Fettus");
    size_t hash3 = String_GetHashCode(g);
    printf("String_nCat:\n%s\n%s\n", g->str, h->str);
    String * gnew =String_nCat(g, h, 9);
    printf("%s\n", gnew->str);
    printf("Old Hash: %zu\nNew Hash: %zu\n\n", hash3, String_GetHashCode(g));
    
    String boba;
    String_New(&boba,"Boba Fett");
    if (String_EqualN(gnew,&boba,9))
        printf("====>String_nCat works\n");
    else
        printf("====>String_nCat does NOT work\n");
    
    free(gnew);
    
    //String_Cmp                                                                                                            Done
    String_New(i, "Darth Vader");
    String_New(j, "Darth Maul");
    printf("String_Cmp: \n%s\n%s\n%d\n\n", i->str, j->str, String_Cmp(i, j));
    
    //String_Cmp                                                                                                            Done
    String *ix;
    String *jx;
    ix = (String *)malloc(sizeof(String));
    jx = (String *) malloc(sizeof(String));
//    ix = malloc(sizeof(String));
//    jx = malloc(sizeof(String));
    String_New(ix, "Darth Vader");
    String_New(jx, "Darth Vader");
    printf("String_Cmp: \n%s\n%s\n%d\n\n", ix->str, jx->str, String_Cmp(ix, jx));
    
    String_Delete(ix);
    String_Delete(jx);
    free(ix);
    free(jx);
    //String_nCmp                                                                                                           Done
    String_New(k, "Gen. Greivous");
    String_New(l, "Gen. Veers");
    printf("String_nCmp: \n%s\n%s\n%d\n\n", k->str, l->str, String_nCmp(k, l, 6));
    
    //String_Chr                                                                                                            Done
    
    String_New(m, "do or do not, there is no try");
    printf("String_Chr: \n%s\n%s\n\n", m->str, String_Chr(m, 'h')->str);
    
    //String_cSpn                                                                                                           Done
    String_New(n, "fcba73");
    String_New(o, "1234567890");
    printf("String_cSpn: \n%s\n%s\n%zu\n\n", n->str, o->str, String_cSpn(n, o));
    //it should be 5
    //String_pBrk                                                                                                           Done
    String_New(p, "Death Star");
    String_New(q, "aeiou");
    printf("String_pBrk: \n%s\n%s\n%s\n\n", p->str, q->str, String_pBrk(p, q)->str);
    
    //String_rChr                                                                                                           Done
    String_New(r, "do or do not, there is no try");
    size_t r11 = String_GetHashCode(r);
    String * r12 = String_rChr(r, 't');
    printf("String_rChr: \n%s\n%s\n", r->str, r12->str);
    printf("Old Hash: %zu\nNew Hash: %zu\n\n", r11, String_GetHashCode(r12));
    
    //String_Spn
    String_New(s, "129th");
    String_New(t, "1234567890");
    printf("String_Spn: \n%s\n%s\n%zu\n\n", s->str, t->str, String_spn(s, t));
    // spn here should return 3.
    
    //String_Str
    // printf("\n===>String_STR: Not present\n");
    String_New(u, "No, I am your mother");
    String_New(v, "your");
    size_t u1 = u->hashcode;
    printf("String_Str:\n%s\n", u->str);
    
    u = String_Str(u, v);
    
    printf("\n%s\t\t\n", u->str);
    printf("Old Hash: %zu\nNew Hash: %zu\n\n", u1, String_GetHashCode(u));
    
    //    //String_Len                                                                                                            Done
    String_New(v, "Jabba The Hutt");
    printf("String_Len: \n%s\n%zu\n\n", v->str, String_Len(v));
    
    
    
    
    
    
    printf("========================================================================\n\n");
    printf("\t\t\t\tAPPENDIX B\n\n");
    
    //Appendix B
    
    //String_Trim                                                                                                           Done
    String_New(aa, "  Clone Troopers  ");
    size_t aa1 = String_GetHashCode(aa);
    printf("String_Trim: \n.%s.\n", aa->str);
    printf(".%s.\n", String_Trim(aa)->str);
    printf("Old Hash: %zu\nNew Hash: %zu\n\n", aa1, String_GetHashCode(aa));
    
    //String_LTrim                                                                                                          Done
    String_New(bb, "  Luke Skywalker    ");
    size_t bb1 = String_GetHashCode(bb);
    printf("String_LTrim:%s; Length:%zu\n", bb->str,bb->size);
    String * ltrim =  String_LTrim(bb);
    printf("Old Hash: %zu\nNew Hash: %zu\n", bb1, String_GetHashCode(bb));
    printf("String_LTrim After:%s; Length:%zu\n\n", ltrim->str,ltrim->size);
    //lenght old should be 20 and old 18... only remove 2 spaces
    
    //String_RTrim                                                                                                          Done
    String_New(cc, "   Jabba The Hutt   ");
    //size_t cc1 = String_GetHashCode(cc);
    printf("String_RTrim:%s; Length:%zu\n", cc->str,cc->size);
    String * rtrim =  String_RTrim(cc);
    printf("%s.\n", String_RTrim(cc)->str);
    printf("String_LTrim After:%s; Length:%zu\n\n", rtrim->str,rtrim->size);
    //old len = 20 , new should be 17 ... remove 3 spaces
    
    //String_GetCharFromIndex                                                                                               Done
    String_New(dd, "ABCDE");
    printf("String_GetCharFromIndex 3 should b D: \n%s\n%c\n\n", dd->str, (char) String_GetCharFromIndex(dd, 3));
    
    //String_IndexOfChar                                                                                                    Done
    String_New(ee, "abcde");
    printf("String_IndexOfChar d should be 3: \n%s\n%zu\n\n", ee->str, String_IndexOfChar(ee, 'd'));
    
    //String_Lower                                                                                                          Done
    String_New(ff, "ABCDE");
    size_t ff1 = ff->hashcode;
    printf("String_Lower: \n%s\n", ff->str);
    printf("%s\n", String_Lower(ff)->str);
    printf("Old Hash: %zu\nNew Hash: %zu\n\n", ff1, String_GetHashCode(ff));
    
    //String_Upper                                                                                                          Done
    String_New(gg, "abcde");
    size_t gg1 = String_GetHashCode(gg);
    printf("String_Upper: \n%s\n", gg->str);
    printf("%s\n", String_Upper(gg)->str);
    printf("Old Hash: %zu\nNew Hash: %zu\n\n", gg1, String_GetHashCode(gg));
    
    //String_Reverse                                                                                                        Done
    String_New(hh, "0123456789");
    size_t hh1 = String_GetHashCode(hh);
    printf("String_Reverse: \n%s\n", hh->str);
    printf("%s\n", String_Reverse(hh)-> str);
    printf("Old Hash: %zu\nNew Hash: %zu\n\n", hh1, String_GetHashCode(hh));
    
    //String_WordCount                                                                                                      Done
    String_New(ii, "Yoda Obi Ani");
    printf("String_WordCount: \n%s\n%zu\n\n", ii->str, String_WordCount(ii));
    //should be 3
    
    String_New(iix, "First Homework : 100 points");
    printf("String_WordCount: \n%s\n%zu\n\n", iix->str, String_WordCount(iix));
    //should be 5
    
    
    /// free memory
    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    free(f);
    free(g);
    free(h);
    free(i);
    free(j);
    free(k);
    free(l);
    free(m);
    free(n);
    free(o);
    free(q); free(r); free(s); free(t); free(u); free(v);
    /// free memory
    free(aa); free(bb); free(cc); free(dd); free(ee); free(ff); free(gg); free(hh);
    free(ii); free(iix);
    
    ArrayList * strListA = (ArrayList *) malloc(sizeof(ArrayList));
    ArrayList * strListB = (ArrayList *) malloc(sizeof(ArrayList));
    boolean checkList = ArrayList_New(strListA);
    boolean checkList2 = ArrayList_New(strListB);
    
    printf("List2 created? %d\n",checkList2);
    
    
    if (!checkList || !checkList2)
    {
        printf("Error initializing arraylists\n");
        return -1;
    }
    
    //ArrayList_Add
    for (int i = 0; i < 400; i++){
        String * str = (String *)malloc(sizeof(String));
        String * str2 = (String *)malloc(sizeof(String));
        String_New(str, "Programming3");
        String_New(str2,"Programming4");
        ArrayList_Add(strListA,str);
        ArrayList_Add(strListB,str2);
    }
    
    String * str1 =  (String *) ArrayList_Get(strListA,100);
    String * str2 =  (String *) ArrayList_Get(strListB,100);
    printf("List 1 member 100 = %s ; List 2 Member 100 = %s\n", str1->str,str2->str);
    ArrayList_Copy(strListA,strListB);
    str1 =  (String *) ArrayList_Get(strListA,100);
    str2 =  (String *) ArrayList_Get(strListB,100);
    printf("After copy List 1 member 100 = %s ; List 2 Member 100 = %s\n", str1->str,str2->str);
    
    printf("Before clear (B): Size = %zu, reserved = %zu \n",strListB->size,strListB->reserved);
    
    
    for (int i =0; i < 400; i++)
    {
        //free strings first.
        String * s = (String *)ArrayList_Get(strListB,i);
        //if your clear does not remove, called remove
        // ArrayList_Remove(strListB, i);
        free(s->str);
        
    }
    //clear list B
    ArrayList_Clear(strListB);
    //if needed called ArrayList_Compact (if you don't call it in clear)
    //ArrayList_Compact(strListB);
    
    printf("After clear (B): Size = %zu, reserved = %zu \n",strListB->size,strListB->reserved);
    
    
    ArrayList_ExpandReserved(strListB, 10000);
    printf("After expand reserved (B): Size = %zu, reserved = %zu \n",strListB->size,strListB->reserved);
    
    for (int i = 0; i < 1000; i++){
        String * str = (String *)malloc(sizeof(String));
        String_New(str,"Programming Class");
        ArrayList_Add(strListB,str);
    }
    
    printf("After adding 1000 (B): Size = %zu, reserved = %zu \n",strListB->size,strListB->reserved);
    
    for (int i = 0; i < 10000; i++){
        String * str = (String *)malloc(sizeof(String));
        String_New(str,"Programming Class");
        ArrayList_Add(strListB,str);
    }
    
    //str1 = ArrayList_Get(strListB,1000);
    //str2 = ArrayList_Get(strListB,5000);
    
    //printf("List member 1000 = %s ; List Member 5000 = %s\n", str1->str,str2->str);
    printf("After adding 10,000 more (now 11,000) (B): Size = %zu, reserved = %zu \n",strListB->size,strListB->reserved);
    
    //modify one of them
    String * strSet = (String *)malloc(sizeof(String));
    String_New(strSet,"Programming 3 Class");
    
    ArrayList_Set(strListB,10500, strSet);
    
    String * strSetPrint= (String *) ArrayList_Get(strListB,10500);
    printf ("New Set :%s\n",strSetPrint->str);
    printf("Before  Loop 11,0000 (B): Size = %zu, reserved = %zu \n",strListB->size,strListB->reserved);
    
    //    printf("Testing getSize for B now = %zu\n",ArrayList_GetSize(strListB));
    //
    //    printf("Testing getSize for A now = %zu\n",ArrayList_GetSize(strListA));
    printf("\n The following indexes are NULL: ");
    for (int i =11000; i >=0; i--)
    {
        String * s = (String *) ArrayList_Get(strListB,i);
        if (s == NULL)
            printf("%d ",i);
        else
            free(s->str);
        ArrayList_RemoveLast(strListB);
    }
    printf("\n");
    printf("After  Loop 11,0000 (B): Size = %zu, reserved = %zu \n",strListB->size,strListB->reserved);
    
    //I'm leaking strings in A but it is ok
    //because I'm exiting now and it is main to be a test.
    //but you can do the loop yourself .
    free(strListB);
    free(strListA);
    
    printf("Element 10500 is %s\n",strSetPrint->str);
    
    
    return 0;
}


