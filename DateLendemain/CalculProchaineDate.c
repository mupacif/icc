int jourLendemain(int day_in, int month_in, int year_in)
{
    int jour_svt ;
    if (((day_in == 29) && (month_in == 2)) || 
    ((day_in == 30) && (mois30j(month_in))) || 
    (day_in == 31) || 
    ((day_in == 28) && (month_in == 2) && (!anneeBissextile(year_in))))
                jour_svt = 1;
    else
               jour_svt = ++day_in ;                      
    return jour_svt;
}


int moisLendemain(int day_out, int month_in)
{
    int mois_svt;
    if (day_out ==1)
        if(month_in == 12)
             mois_svt = 1;
        else
            mois_svt = ++month_in;
    else
       mois_svt = month_in;             
             
    return mois_svt ;
}


int anneeLendemain(int year_in, int day_out, int month_out)
{
    if ((day_out == 1) && (month_out == 1))
    return (year_in == -1) ? year_in + 2 : ++year_in;

    return year_in;
}

/*
int mois31j(int mois)
{
    switch (mois)
    {
           case 1 :
           case 3 :
           case 5 :
           case 7 :
           case 8 :
           case 10 :               
           case 12: return 1;
           default : return 0;
    }                     
}        
*/
