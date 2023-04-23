    vector<PROCESSES>::iterator IT;
        cout<<TOTbt<<endl<<endl;
    for(int i=0;i<TOTbt;i++)
    {
        cout<<i<<"-->";
        for(IT=ALIST[i].P.begin();IT!=ALIST[i].P.end();++IT)
        {
            cout<<"P"<<(*IT).index<<", ";
        }
        cout<<endl;

    }