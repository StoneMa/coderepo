void mergelklist(lklist *ha,lklist *hb,lklist *&hc) {
    lklist *s=hc=0;
    while(ha!=0 && hb!=0)
    {
        if(ha->data<hb->data)
        {
            if(s==0) hc=s=ha;
            else {
                s->next=ha;
                s=ha; };
            ha=ha->next;
        }
        else
        {
            if(s==0) hc=s=hb;
            else{
                s->next=hb;
                s=hb;
                }
            hb=hb->next;
        }
    }
    if(ha==0) s->next=hb;
    else s->next=ha;
    }
