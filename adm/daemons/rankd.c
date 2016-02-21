//Cracked by Roath
// rankd.c

#include <ansi.h>

//descriptions...

//note, be careful with the size of this list, dx increases as n^3. 
string *dx_level_desc = ({
	BLU "�����;" NOR, //in unit of year 
	BLU "�ŵ���ϲ" NOR, //1x2=2   
	BLU "�������" NOR, //8x2=16
	BLU "��ͨ����" NOR, //27x2=56    
	HIB "����Ѿ�" NOR, //64x2=128
	HIB "Ԫ�����" NOR, //125x2=250
	HIB "�����ȹ�" NOR, //216x2=432    
	HIB "һ��ǧ��" NOR, //343x2=686
	CYN "���ߵ�¡" NOR, //512x2=1024
	CYN "��̥����" NOR, //729x2=1458    
	CYN "ϼ�ٷ���" NOR, //1000x2=2000
	CYN "��������" NOR, //1331x2=2662    
	HIC "�����ֻ�" NOR, //1728x2=3456
	HIC "��֤���" NOR, //2197x2=4394    
	HIC "��豹���" NOR, //2744x2=5688 
	HIW "���˺�һ" NOR, //3375x2=6750
         BLINK HIC "����"HIW"����" NOR
});

string *fali_level_desc = ({
	BLU "���߷���" NOR, //    
	BLU "�����仯" NOR, //1x40=40
	BLU "��������" NOR, //4x40=160
	HIB "���Ƽ���" NOR, //9x40=360   
	HIB "�����û" NOR, //16x40=640
	HIB "Ԥ֪����" NOR, //25x40=1000
	HIB "�������" NOR, //36x40=1440    
	CYN "���绽��" NOR, //49x40=1960
	CYN "������ɽ" NOR, //64x40=2560    
	CYN "���ǻ���" NOR, //81x40=3240
	CYN "��������" NOR, //100x40=4000
	HIC "��������" NOR, //121x40=4840    
	HIC "�任Ī��" NOR, //144x40=5760
	HIW "�����ޱ�" NOR  //169x40=6760
});

string *exp_level_desc = ({
	BLU "��ѧէ��" NOR,
	BLU "�����ž�" NOR,
	HIB "��ͨƤë" NOR,
	HIB "��֪һ��" NOR,
	YEL "��������" NOR,
	YEL "������" NOR,
	HIY "����С��" NOR,
	HIY "����Ѿ�" NOR,
	HIM "�������" NOR,
	HIM "��Ȼ����" NOR,
	HIR "�������" NOR,
	HIR "�������" NOR,
	MAG "����似" NOR,
	MAG "�����뻯" NOR,
	CYN "��Ȼ��ͨ" NOR,
	CYN "�Ƿ��켫" NOR,
	HIC "������˫" NOR,
	HIC "һ����ʦ" NOR,
	HIC "������" NOR,
	HIW "��ɲ�" NOR,
        WHT "�ݺ����" NOR,
         HIR "�޵�"HIY"�칬" NOR,
        HIC "Ц��"HIW"����" NOR,
          BLINK HIR "��"HIY"��"HIC"֮"HIW"��" NOR
});

string *yishu_level_desc = ({
       BLU "��ͨҩ��" NOR, // i*i*2
	BLU "����ҽ;" NOR, //    
	BLU "��ҽ��ϲ" NOR, //
	BLU "����ҽ��" NOR, //
	HIB "ҽ�¸���" NOR, //
	HIB "ҽ���г�" NOR, //
	HIB "�������" NOR, //
	HIB "��Ȼ���� " NOR, //
	CYN "�������" NOR, //
	CYN "������ҽ" NOR, //
	CYN "�������" NOR, //
	CYN "��������" NOR, //
	HIC "ҽ��ͨ��" NOR, //
	HIW "�� �� ��" NOR  //
});
string describe_dx(int value)
{
	int grade, two_year, n;
	
	two_year = value/2000;
	for(grade=0; grade<sizeof(dx_level_desc); grade++)
//sizeof(dx_level_desc)
	{
		n = (grade+1)*(grade+1)*(grade+1);
		if( two_year<n ) break;
	}
	if( grade>=sizeof(dx_level_desc) ) grade=sizeof(dx_level_desc)-1;
	return dx_level_desc[grade];
}

int grade_dx(string desc)
{
	int grade, n;

	for(grade=0; grade<sizeof(dx_level_desc); grade++) 
	{
		n = grade;
		if ( dx_level_desc[grade] == desc )
			return n;
	}
	return 0;
}

string describe_exp(int value)
{
	int grade, lvl , n;
	
	lvl = (value*2)/675;
	//note, this is to make ��ɲ� requires 2700k combat_exp,
	//which also means player can learn skill level to 300.

	for(grade=0; grade<sizeof(exp_level_desc); grade++) 
	{
		n = (grade+1)*(grade+1)*(grade+1);
		if( lvl<n ) break;
	}
	if( grade>=sizeof(exp_level_desc) ) grade=sizeof(exp_level_desc)-1;
	return exp_level_desc[grade];
}

int grade_exp(string desc)
{
	int grade, n;

	for(grade=0; grade<sizeof(exp_level_desc); grade++) 
	{
		n = grade;
		if ( exp_level_desc[grade] == desc )
			return n;
	}
	return 0;
}

string describe_neili(int value)
{
	int year, sixty, left;
	string line;
	
	year = value/100;
	sixty = year/60;
	left = year - sixty*60;

	if( year <= 0 )
	{
		line = HIB "����һ��" NOR;
		return line;
	}
	
	if(sixty > 0 )
	{
		if ( left != 0 )
		{ 
			line = HIW + chinese_number(sixty) + "����" + NOR + "��" +  HIR + chinese_number(left) + "��" + NOR;
		}
		else 
		{
			line = HIW + chinese_number(sixty) + "����"  + NOR;	
		}		
	}
	else 
		line = HIR + chinese_number(year)+"��" + NOR;

	return line;
}

string describe_fali(int value)
{
	int grade, lvl, n;

	//in unit of 40, increase by n^2.
	lvl=value/40;
	for(grade=0; grade<sizeof(fali_level_desc); grade++) 
	{
		n=(grade+1)*(grade+1);
		if( lvl<n ) break;
	}
	if( grade>=sizeof(fali_level_desc) ) grade=sizeof(fali_level_desc)-1;
	return fali_level_desc[grade];
}
 
int grade_fali(string desc)
{
	int grade;

	for(grade=0; grade<sizeof(fali_level_desc); grade++) 
	{
		if ( (string)fali_level_desc[grade] == desc )
			return grade;
	}
	return 0;
}

string describe_yishu(int value)
{
        int grade, n , two_lvl;
      two_lvl = value/2;
        for(grade=0; grade<sizeof(yishu_level_desc); grade++) 
        {
            n = (grade+1)*(grade+1);
                if( two_lvl<n ) break;
        }
        if( grade>=sizeof(yishu_level_desc) ) grade=sizeof(yishu_level_desc)-1;
        return yishu_level_desc[grade];
}

int grade_yishu(string desc)
{
        int grade, n;
        for(grade=0; grade<sizeof(yishu_level_desc); grade++) 
        {
                n = grade;
                if ( yishu_level_desc[grade] == desc )
                        return n;
        }
        return 0;
}
string query_description(int type)
{
    int i;
    string *level_desc;
    string line = "";
    if(type==0) level_desc = dx_level_desc;
    else if(type==1) level_desc = exp_level_desc;
    else level_desc = fali_level_desc;
    
    for(i=0; i<sizeof(level_desc); i++)
    {
	line += level_desc[i] + "    ";
	if( (i%4)==3 ) line += "\n";
    }
    
    return line;
}

string _query_rank(object ob);

string query_rank(object ob)
{
    string rank=_query_rank(ob);
    string s1,s2,s3;
    int len, len1, len2;
    
    if(sscanf(rank,"%s��%s��%s",s1,s2,s3)!=3) return rank;
    len=14-sizeof(s2);
    if(len<1) return rank;

    len1=len/2;
    len2=len-len1;
    if(len1) s2=repeat_string(" ",len1)+s2;
    if(len2) s2+=repeat_string(" ",len2);
    
    return s1+"��"+s2+"��"+s3;
}

string _query_rank(object ob)
{
	string at;
	int dx, exp, avg;

	if(strlen(ob->query("added_title"))<1) ob->set("added_title", "����");
	//need this default, otherwise looks too ugly sometimes.

	at = ob->query("added_title");
	dx = (int)ob->query("daoxing");
	exp = (int)ob->query("combat_exp");
	avg = (dx + exp)/2;

	if( ob->is_ghost() ) return HIB "�� ��  �� ��" NOR;
	switch(ob->query("gender")) 
	{
	case "Ů��":
		switch(wizhood(ob)) {
                        case "(admin)": return HIW "�� ����ۺ� ��" NOR;
                        case "(arch)":          return HIR "�� ������� ��" NOR;
                        case "(wizard)":        return HIC "�� ������Ů ��" NOR;
                        case "(apprentice)":    return HIW "����ϰ��Ů��" NOR;
                                case "(immortal)":      return HIW "��������Ů��" NOR;
                                case "(elder)":         return HIG "��������ҡ�" NOR;
			default:
				switch(ob->query("class")) 
				{
//------------------rank for girls--------------------
case "tianpeng":
if ( ob->query("family/family_name") == "����Ԫ˧��" )
        if(dx<1000) 
                return HIR "�� Ů�ұ� ��" NOR;
        else if(dx<10000) 
                 return HIR "�� Ů�ҽ� ��" NOR;
        else if(dx<500000) 
                return HIR "�� �һ��� ��" NOR;
        else if(dx<1000000) 
                return HIR "��"+at+"Ԫ˧�һ�����" NOR;
        else 
                return HIR "��"+at+"Ԫ˧�����š�" NOR;
                break; 
case "kunlun":
             if(dx<1000)  
                    return RED "�� С��Ů ��" NOR; 
             if(dx<10000)  
                    return RED "�� С�ɹ� ��" NOR; 
             if(dx<100000)  
                    return RED "�� ��  �� ��" NOR; 
             if(dx<500000)  
                    return RED "��"+at+"��á�" NOR; 
             if(dx<700000)
                    return RED "��"+at+"ʥ��á�" NOR; 
            else  
                return HIW "��"+at+"ʥ��ĸ��" NOR;
            break; 
case "youxia":
                if(dx<1000)  
                        return HIM "�� Ů  �� ��" NOR; 
                else if(dx<10000)  
                        return HIM "�� Ů���� ��" NOR; 
                else if(dx<500000)  
                        return HIM "�� "+at+"��Ů ��" NOR; 
                else if(dx<1000000)  
                        return HIM "�� "+at+"���� ��" NOR; 
                else  
                        return HIM "�� "+at+"ʥ�� ��" NOR; 
                break; 
case "wusheng":		           
	if(dx<1000) 
		return GRN "�� ����ɲ ��" NOR;
	else if(dx<10000) 
		return GRN "�� Ů�޺� ��" NOR;	
	else if(dx<100000) 
		return GRN "�� ���� ��" NOR;
	else if(dx<500000) 
		return GRN "��"+at+"���ߡ�" NOR;	
	else 
		return GRN "��"+at+"ʥ����" NOR;
	break;
case "sanjie":
if ( ob->query("family/family_name") == "����ɽ" )
	if(dx<1000) 
		return HIR "�� СħŮ ��" NOR;
	else if(dx<10000) 
		return HIR "�� ������ ��" NOR;
	else if(dx<500000) 
		return HIR "�� ħ��Ů ��" NOR;
	else if(dx<1000000) 
		return HIR "��"+at+"Ůħ����" NOR;
	else 
		return HIR "��"+at+"��Ůħ����" NOR;
	break;		

/*
if ( ob->query("family/family_name") == "��һ��" )
	if(dx<1000) 
		return HIR "�� ������ ��" NOR;
	else if(dx<10000) 
		return HIR "�� �ɡ��� ��" NOR;
	else if(dx<500000) 
		return HIR "�� ����Ů ��" NOR;
	else if(dx<1000000) 
		return HIR "��"+at+"ʥŮ��" NOR;
	else 
		return HIR "��"+at+"ʥĸ��" NOR;
		
if ( ob->query("family/family_name") == "������" )
	if(dx<1000) 
		return HIR "�� ����Ů ��" NOR;
	else if(dx<10000) 
		return HIR "�� ������ ��" NOR;
	else if(dx<500000) 
		return HIR "�� ������ ��" NOR;
	else if(dx<1000000) 
		return HIR "��"+at+"Ů������" NOR;
	else 
		return HIR "��"+at+"��Ů������" NOR;
		
if ( ob->query("family/family_name") == "��ħ��" )
	if(dx<1000) 
		return HIR "�� СħŮ ��" NOR;
	else if(dx<10000) 
		return HIR "�� ������ ��" NOR;
	else if(dx<500000) 
		return HIR "�� ħ��Ů ��" NOR;
	else if(dx<1000000) 
		return HIR "��"+at+"Ůħ����" NOR;
	else 
		return HIR "��"+at+"��Ůħ����" NOR;
		
if ( ob->query("family/family_name") == "��ʬ��" )
	if(dx<1000) 
		return HIR "�� Ů��ʬ ��" NOR;
	else if(dx<10000) 
		return HIR "�� Ůɥʬ ��" NOR;
	else if(dx<500000) 
		return HIR "�� Ů��ʬ ��" NOR;
	else if(dx<1000000) 
		return HIR "��"+at+"ɥʬ����" NOR;
	else 
		return HIR "��"+at+"��ʬ����" NOR;

if ( ob->query("family/family_name") == "�׵���" )
	if(dx<1000) 
		return HIR "�� Ů���� ��" NOR;
	else if(dx<10000) 
		return HIR "�� Ů���� ��" NOR;
	else if(dx<500000) 
		return HIR "�� Ů���� ��" NOR;
	else if(dx<1000000) 
		return HIR "��"+at+"Ů���ɡ�" NOR;
	else 
		return HIR "��"+at+"Ů������" NOR;
	break;
*/

case "swordsman":
	if(dx<1000) 
		return HIC "�� Ů��ͯ ��" NOR;
	else if(dx<10000) 
		return HIC "�� Ů��ʿ ��" NOR;
	else if(dx<500000) 
		return HIC "�� Ů���� ��" NOR;
	else if(dx<1000000) 
		return HIC "��"+at+"���ɡ�" NOR;
	else 
		return HIC "��"+at+"��ʥ��" NOR;
	break;
case "xian":
	if(dx<1000) 
		return HIM "�� ��  Ů ��" NOR;
	else if(dx<10000) 
		return HIM "�� С��Ů ��" NOR;	
	else if(dx<100000) 
		return HIM "�� ��  Ů ��" NOR;
	else if(dx<500000) 
		return HIM "��"+at+"������" NOR;	
 else if ( ob->query("family/family_name") == "��ׯ��" )
       return HIC "��"+at+"���ɡ�" NOR;
   else
		return HIM "��"+at+"���" NOR;
	break;
case "yaomo":
if ( ob->query("family/family_name") == "��˿��" )
	if(avg<1000) 
		return MAG "�� С��Ů ��" NOR;
	else if(avg<10000) 
		return MAG "�� ��  �� ��" NOR;	
	else if(avg<100000) 
		return MAG "�� Ů  ħ ��" NOR;
	else if(avg<500000) 
		return MAG "��"+at+"ħŮ��" NOR;	
	else 
		return MAG "��"+at+"Ůħ����" NOR;
if ( ob->query("family/family_name") == "���ƶ�" )
	if(avg<1000) 
		return RED "�� С��Ů ��" NOR;
	else if(avg<10000) 
		return RED "�� ��  �� ��" NOR;	
	else if(avg<100000) 
		return RED "�� Ů  ħ ��" NOR;
	else if(avg<500000) 
		return RED "��"+at+"ħŮ��" NOR;	
	else 
		return RED "��"+at+"Ůħ����" NOR;
if ( ob->query("family/family_name") == "��ѩɽ" )
	
		if(avg<1000) 
		return HIW "�� С��Ů ��" NOR;
	else if(avg<10000) 
		return HIW "�� ��  �� ��" NOR;	
	else if(avg<100000) 
		return HIW "�� Ů  ħ ��" NOR;
	else if(avg<500000) 
		return HIW "��"+at+"ħŮ��" NOR;	
	else 
		return HIW "��"+at+"Ůħ����" NOR;

if ( ob->query("family/family_name") == "�ݿ�ɽ�޵׶�" )
		if(avg<1000) 
		return YEL "�� С��Ů ��" NOR;
	else if(avg<10000) 
		return YEL "�� ��  �� ��" NOR;	
	else if(avg<100000) 
		return YEL "�� Ů  ħ ��" NOR;
	else if(avg<500000) 
		return YEL "��"+at+"ħŮ��" NOR;	
	else 
		return YEL "��"+at+"Ůħ����" NOR;

	break;
case "bonze":		
	if(dx<1000) 
		return HIY "�� С��� ��" NOR;
	else if(dx<10000) 
		return HIY "�� Сʦ̫ ��" NOR;	
	else if(dx<100000) 
		return HIY "�� ʥ  �� ��" NOR;
	else if(dx<500000) 
		return HIY "��"+at+"���᡿" NOR;	
	else 
		return HIY "��"+at+"������" NOR;
	break;
case "taoist":		           
	if(dx<1000) 
		return HIG "�� Ů��ͯ ��" NOR;
	else if(dx<10000) 
		return HIG "�� С���� ��" NOR;	
	else if(dx<100000) 
		return HIG "�� ��  Ů ��" NOR;
	else if(dx<500000) 
		return HIG "��"+at+"��Ů��" NOR;	
	else 
		return HIG "��"+at+"ʥĸ��" NOR;
	break;
case "dragon":		
	if(avg<1000) 
		return HIC "�� С���� ��" NOR;
	else if(avg<10000) 
		return HIC "�� ĸҹ�� ��" NOR;	
	else if(avg<100000) 
		return HIC "�� С��Ů ��" NOR;
	else if(avg<500000) 
		return HIC "��"+at+"��Ů��" NOR;	
	else 
		return HIC "��"+at+"������" NOR;
	break;
case "scholar":
	if( (string)at=="δ��" )
	{
		if((int)ob->query_skill("literate", 1)<20) 
			return GRN "�� Ůѧͯ ��" NOR;
		else if((int)ob->query_skill("literate", 1)<100) 
			return GRN "�� ��  Ů ��" NOR;
		else 
			return GRN "�� Ůѧʿ ��" NOR;
	}
	else
	{
		if((int)ob->query_skill("literate", 1)<20) 
			return GRN "�� Ůѧͯ ��" NOR;
		else if((int)ob->query_skill("literate", 1)<100) 
			return GRN "��"+at+"��š�" NOR;
		else 
			return GRN "��"+at+"ѧʿ��" NOR;
	}
	break;
case "fighter":		
	if(exp<1000) 
		return HIR "�� Ů  �� ��" NOR;
	else if(exp<10000) 
		return HIR "�� Ů�ν� ��" NOR;	
	else if(exp<100000) 
		return HIR "�� Ů���� ��" NOR;
	else if(exp<500000) 
		return HIR "��"+at+"�󽫾���" NOR;	
	else 
		return HIR "��"+at+"��Ԫ˧��" NOR;
	break;
case "youling":	
	if(avg<1000) 
		return HIB "������С��" NOR;
	else if(avg<10000) 
		return HIB "���Ի�Ů��" NOR;	
	else if(avg<100000) 
		return HIB "����ڤŮʹ��" NOR;
	else if(avg<500000) 
		return HIB "��"+at+"���ޡ�" NOR;	
	else 
		return HIB "��"+at+"Ů����" NOR;
	break;	
case "dancer":
	return GRN "�� ��  �� ��" NOR;	
	break;
default:			
        return  HIM "��  ��  Ů  ��" NOR;
//------------------end rank for girls--------------------
				}
			}
//begin ���ԣ�
	default:
		switch(wizhood(ob)) 
		{
                        case "(admin)":         return HIW "�� ������� ��" NOR;
                        case "(arch)":                  return HIR "�� �������� ��" NOR;
                        case "(wizard)":        return HIC "�� ������� ��" NOR;
                        case "(apprentice)":                return HIW "����ϰ��ʦ��" NOR;
                                case "(immortal)":               return HIW "��������ʦ��" NOR;
                        case "(elder)":                     return HIW "��������ҡ�" NOR;
			default:
				switch(ob->query("class")) 
				{
//------------------rank for men--------------------
case "tianpeng":
        if(dx<1000) 
                return GRN "�� �мҶ� ��" NOR;
        else if(dx<10000) 
                return GRN "�� ��ս�� ��" NOR;  
        else if(dx<100000) 
                return GRN "�� �󻤷� ��" NOR;
        else if(dx<500000) 
                return GRN "��"+at+"Ԫ˧�󻤷���" NOR;        
        else 
                return GRN "��"+at+"Ԫ˧�����š�" NOR;
        break;
case "kunlun":                    
             if(dx<1000)  
                return CYN "�� С  �� ��" NOR;
             if(dx<10000)  
                return CYN "�� ��  �� ��" NOR;
             if(dx<100000)  
                return CYN "�� ��  �� ��" NOR;
             if(dx<500000)  
                return CYN "��"+at+"���ɡ�" NOR;
             if(dx<700000)  
                return CYN "��"+at+"ʥ���ɡ�" NOR;
            else  
                return HIW "��"+at+"ʥ����" NOR;
            break; 
case "youxia":
        if(dx<1000) 
                 return HIC "�� �� �� ��" NOR;
        else if(dx<10000) 
                return HIC "�� �� �� ��" NOR;  
        else if(dx<100000) 
                return HIC "�� "+at+"��ʿ ��" NOR;
        else if(dx<500000) 
                return HIC "�� "+at+"���� ��" NOR;
        else 
                return HIC "�� "+at+"ʥ�� ��" NOR;
        break;
case "wusheng":                    
	if(dx<1000) 
		return GRN "�� ����ɲ ��" NOR;
	else if(dx<10000) 
		return GRN "�� ���޺� ��" NOR;	
	else if(dx<100000) 
		return GRN "�� ���� ��" NOR;
	else if(dx<500000) 
		return GRN "��"+at+"���ߡ�" NOR;	
	else 
		return GRN "��"+at+"��ۡ�" NOR;
	break;
case "sanjie":
if ( ob->query("family/family_name") == "����ɽ" )
	if(dx<1000) 
		return HIR "�� ��ɢ�� ��" NOR;
	else if(dx<10000) 
		return HIR "�� ��ʥ�� ��" NOR;
	else if(dx<500000) 
		return HIR "�� �桡�� ��" NOR;
	else if(dx<1000000) 
		return HIR "��"+at+"����ħ��" NOR;
	else 
		return HIR "��"+at+"Ԫ��" NOR;

/*
if ( ob->query("family/family_name") == "��һ��" )
	if(dx<1000) 
		return HIR "�� ������ ��" NOR;
	else if(dx<10000) 
		return HIR "�� �ɡ��� ��" NOR;
	else if(dx<500000) 
		return HIR "�� �桡�� ��" NOR;
	else if(dx<1000000) 
		return HIR "��"+at+"��ʦ��" NOR;
	else 
		return HIR "��"+at+"��ʦ��" NOR;
		
if ( ob->query("family/family_name") == "������" )
	if(dx<1000) 
		return HIR "�� С���� ��" NOR;
	else if(dx<10000) 
		return HIR "�� ������ ��" NOR;
	else if(dx<500000) 
		return HIR "�� ������ ��" NOR;
	else if(dx<1000000) 
		return HIR "��"+at+"������" NOR;
	else 
		return HIR "��"+at+"��������" NOR;
		
if ( ob->query("family/family_name") == "��ħ��" )
	if(dx<1000) 
		return HIR "�� Сħͷ ��" NOR;
	else if(dx<10000) 
		return HIR "�� ħ���� ��" NOR;
	else if(dx<500000) 
		return HIR "�� ħ��ͷ ��" NOR;
	else if(dx<1000000) 
		return HIR "��"+at+"ħ����" NOR;
	else 
		return HIR "��"+at+"��ħ����" NOR;
		
if ( ob->query("family/family_name") == "��ʬ��" )
	if(dx<1000) 
		return HIR "�� ����ʬ ��" NOR;
	else if(dx<10000) 
		return HIR "�� ɥ��ʬ ��" NOR;
	else if(dx<500000) 
		return HIR "�� ����ʬ ��" NOR;
	else if(dx<1000000) 
		return HIR "��"+at+"ɥʬ����" NOR;
	else 
		return HIR "��"+at+"��ʬ����" NOR;

if ( ob->query("family/family_name") == "�׵���" )
	if(dx<1000) 
		return HIR "�� ������ ��" NOR;
	else if(dx<10000) 
		return HIR "�� ������ ��" NOR;
	else if(dx<500000) 
		return HIR "�� ������ ��" NOR;
	else if(dx<1000000) 
		return HIR "��"+at+"���ɡ�" NOR;
	else 
		return HIR "��"+at+"������" NOR;
	break;
*/

case "swordsman":
	if(dx<1000) 
		return HIC "�� ��  ͯ ��" NOR;
	else if(dx<10000) 
		return HIC "�� ��  ʿ ��" NOR;
	else if(dx<100000) 
		return HIC "�� ��  �� ��" NOR;
	else if(dx<500000) 
		return HIC "��"+at+"���ɡ�" NOR;
	else 
		return HIC "��"+at+"��ʥ��" NOR;
	break;
case "xian":	            	
	if(dx<1000) 
		return RED "�� ��  ͯ ��" NOR;
	else if(dx<10000) 
		return RED "�� ɢ  �� ��" NOR;	
	else if(dx<100000) 
		return RED "�� ��  �� ��" NOR;
	else if(dx<500000) 
		return RED "��"+at+"���ɡ�" NOR;	
	else if(dx<1000000) 
		return RED "��"+at+"�����" NOR;
	else 
		return RED "��"+at+"����" NOR;
	break;
case "yaomo":
if ( ob->query("family/family_name") == "���ƶ�" )
	if(avg<1000) 
		return RED "�� С  �� ��" NOR;
	else if(avg<10000) 
		return RED "�� ��  �� ��" NOR;	
	else if(avg<100000) 
		return RED "�� ��  �� ��" NOR;
	else if(avg<500000) 
		return RED "�� "+at+"�� ��" NOR;	
	else if(avg<1000000) 
		return RED "��"+at+"��ħ��" NOR;
	else 
		return RED "��"+at+"ħ����" NOR;
	if ( ob->query("family/family_name") == "��˿��" )
	if(avg<1000) 
		return MAG "�� С  �� ��" NOR;
	else if(avg<10000) 
		return MAG "�� ��  �� ��" NOR;	
	else if(avg<100000) 
		return MAG "�� ��  �� ��" NOR;
	else if(avg<500000) 
		return MAG "�� "+at+"�� ��" NOR;	
	else if(avg<1000000) 
		return MAG "��"+at+"��ħ��" NOR;
	else 
		return MAG "��"+at+"ħ����" NOR;
 if ( ob->query("family/family_name") == "��ѩɽ" )

		if(avg<1000) 
		return HIW "�� С  �� ��" NOR;
	else if(avg<10000) 
		return HIW "�� ��  �� ��" NOR;	
	else if(avg<100000) 
		return HIW "�� ��  �� ��" NOR;
	else if(avg<500000) 
		return HIW "�� "+at+"�� ��" NOR;	
	else if(avg<1000000) 
		return HIW "��"+at+"��ħ��" NOR;
	else 
		return HIW "��"+at+"ħ����" NOR;
 if ( ob->query("family/family_name") == "�ݿ�ɽ�޵׶�" )

		if(avg<1000) 
		return YEL "�� С  �� ��" NOR;
	else if(avg<10000) 
		return YEL "�� ��  �� ��" NOR;	
	else if(avg<100000) 
		return YEL "�� ��  �� ��" NOR;
	else if(avg<500000) 
		return YEL "�� "+at+"�� ��" NOR;	
	else if(avg<1000000) 
		return YEL "��"+at+"��ħ��" NOR;
	else 
		return YEL "��"+at+"ħ����" NOR;

	break;
case "bonze":		
	if(dx<1000) 
		return HIY "�� С���� ��" NOR;
	else if(dx<10000) 
		return HIY "�� ��  �� ��" NOR;	
	else if(dx<100000) 
		return HIY "�� ʥ  ɮ ��" NOR;
	else if(dx<500000) 
		return HIY "��"+at+"��ʦ��" NOR;	
	else if(dx<1000000) 
		return HIY "��"+at+"���ϡ�" NOR;
	else 
		return HIY "��"+at+"��" NOR;
	break;
case "taoist":		            
	if(dx<1000) 
		return HIG "�� С��ʿ ��" NOR;
	else if(dx<10000) 
		return HIG "�� ��  ʿ ��" NOR;	
	else if(dx<100000) 
		return HIG "�� ��  �� ��" NOR;
	else if(dx<500000) 
		return HIG "��"+at+"��ʦ��" NOR;	
	else if(dx<1000000) 
		return HIG "��"+at+"���ˡ�" NOR;
	else 
		return HIG "��"+at+"��ʦ��" NOR;
	break;
case "dragon":		
	if(avg<1000) 
		return HIC "�� Ϻ  �� ��" NOR;
	else if(avg<10000) 
		return HIC "�� з  �� ��" NOR;	
	else if(avg<100000) 
		return HIC "��Ѳ��ҹ�桿" NOR;
	else if(avg<500000) 
		return HIC "��"+at+"ҹ�桿" NOR;	
	else if(avg<1000000) 
		return HIC "��"+at+"����" NOR;
	else 
		return HIC "��"+at+"������" NOR;
	break;
case "scholar":
	if( (string)at=="����" )
	{
		if((int)ob->query_skill("literate", 1)<20) 
			return RED "�� ͯ  �� ��" NOR;
		else if((int)ob->query_skill("literate", 1)<100) 
			return RED "�� ��  �� ��" NOR;
		else 
			return RED "�� ��ѧʿ ��" NOR;
	}
	else
	{
		if((int)ob->query_skill("literate", 1)<20) 
			return RED "�� ͯ  �� ��" NOR;
		else if((int)ob->query_skill("literate", 1)<100) 
			return RED "��"+at+"��š�" NOR;
		else 
			return RED "��"+at+"ѧʿ��" NOR;
	}
	break;
case "fighter":		
	if(exp<1000) 
		return HIR "�� С  �� ��" NOR;
	else if(exp<10000) 
		return HIR "�� С  У ��" NOR;	
	else if(exp<100000) 
		return HIR "�� ��  �� ��" NOR;
	else if(exp<500000) 
		return HIR "��"+at+"������" NOR;	
	else if(exp<1000000) 
		return HIR "��"+at+"�󽫾���" NOR;
	else 
		return HIR "��"+at+"��Ԫ˧��" NOR;
	break;
case "youling":	
	if(avg<1000) 
		return HIB "������С��" NOR;
	else if(avg<10000) 
		return HIB "������ʹ�ߡ�" NOR;	
	else if(avg<100000) 
		return HIB "���ظ��й١�" NOR;
	else if(avg<500000) 
		return HIB "��"+at+"�޳���" NOR;	
	else if(avg<1000000) 
		return HIB "��"+at+"����" NOR;
	else 
		return HIB "��"+at+"ڤ����" NOR;
	break;
default:
        return "��  ��  ��  ��";
//------------------end rank for men--------------------
				}
			}
	}
}

string query_respect(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/respect")) )
		return str;

	// added by snowcat
	age = ob->query("fake_age");
	if (age == 0) age = ob->query("age");
	switch(ob->query("gender")) 
	{
		case "Ů��":
			switch(ob->query("class")) 
			{
case "bonze":
	if( age < 18 ) return "Сʦ̫";
	else return "ʦ̫";
	break;
case "taoist":
	if( age < 18 ) return "С�ɹ�";
	else return "�ɹ�";
	break;
case "xian":
	if( age < 18 ) return "С�ɹ�";
	else return "�ɹ�";
	break;
default:
	if( age < 18 ) return "С����";
	else if( age < 50 ) return "����";
	else return "����";
	break;
			}
		case "����":
		default:
			switch(ob->query("class")) 
			{
case "xian":
	if( age < 18 ) return "С����";
	else if( age < 50 ) return "����";
	else return "������";
	break;
case "bonze":
	if( age < 18 ) return "Сʦ��";
	else if( age < 50 ) return "��ʦ";
	else return "����";
	break;
case "taoist":
	if( age < 18 ) return "С��ү";
	else if( age < 50 ) return "����";
	else return "����";
	break;
case "fighter":
	if( age < 18 ) return "С����";
	else if( age < 50 ) return "�󽫾�";
	else return "�Ͻ���";
	break;
case "scholar":
	if( age < 18 ) return "С�๫";
	else if( age < 50 ) return "�๫";
	else return "������";
	break;
case "swordsman":
	if( age < 18 ) return "С�ϵ�";
	else if( age < 50 ) return "׳ʿ";
	else return "��ǰ��";
	break;
default:
	if( age < 18 ) return "С�ֵ�";
	else if( age < 50 ) return "׳ʿ";
	else return "��ү��";
	break;
			}
	}
}

string query_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/rude")) )
		return str;

	// added by snowcat
	age = ob->query("fake_age");
	if (age == 0) age = ob->query("age");
	switch(ob->query("gender")) 
	{
		case "Ů��":
			switch(ob->query("class")) 
			{
case "xian":
	if(age < 30) return "С����";
	else if(age < 50) return "��Ů";
	else return "������";
	break;
case "yaomo":
	if(age < 30) return "С��Ů";
	else if(age < 50) return "��Ů";
	else return "������";
	break;
case "bonze":
	if(age < 30) return "С����";
	else if(age < 50) return "����";
	else return "������";
	break;
case "taoist":
	if(age < 30) return "С��Ů";
	else if(age < 50) return "��Ů";
	else return "������";
	break;
default:
	if( age < 30 ) return "С����";
	else if(age < 50) return "����";
	else return "����̫��";
	break;
			}
		case "����":
		default:
			switch(ob->query("class")) 
			{
case "xian":
	if( age < 50 ) return "������";
	else return "������";
	break;
case "yaomo":
	if( age < 50 ) return "������";
	else return "������";
	break;
case "bonze":
	if( age < 50 ) return "��ͺ¿";
	else return "��ͺ¿";
	break;
case "taoist":
	return "��ţ����";
	break;
case "scholar":
	if( age < 18 ) return "С�����";
	else if( age < 50 ) return "�������";
	else return "��ͯ��";
	break;
default:
	if( age < 18 ) return "С���˵�";
	else if( age < 50 ) return "����";
	else return "��ƥ��";
	break;
			}
	}
}

string query_self(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self")) )
		return str;

	// added by snowcat
	age = ob->query("fake_age");
	if (age == 0) age = ob->query("age");
	switch(ob->query("gender")) 
	{
		case "Ů��":
			switch(ob->query("class")) 
			{
case "bonze":
	if( age < 50 ) return "ƶ��";
	else return "����";
	break;
default:
	if( age < 30 ) return "СŮ��";
	else return "���";
	break;
			}
		case "����":
		default:
			switch(ob->query("class")) 
			{
case "bonze":
	if( age < 50 ) return "ƶɮ";
	else return "����";
	break;
case "taoist":
	return "ƶ��";
	break;
case "scholar":
	if( age < 30 ) return "����";
	else return "����";
	break;
default:
	if( age < 50 ) return "����";
	else return "��ͷ��";
	break;
			}
	}
}

string query_self_rude(object ob)
{
	int age;
	string str;

	if( stringp(str = ob->query("rank_info/self_rude")) )
		return str;

	// added by snowcat
	age = ob->query("fake_age");
	if (age == 0) age = ob->query("age");
	switch(ob->query("gender")) 
	{
		case "Ů��":
			switch(ob->query("class")) 
			{
case "bonze":
	if( age < 50 ) return "ƶ��";
	else return "����";
	break;
default:
	if( age < 50 ) return "������";
	else return "����";
	break;
			}
		case "����":
		default:
			switch(ob->query("class")) 
			{
case "bonze":
	if( age < 50 ) return "�������";
	else return "�Ϻ�����";
	break;
case "taoist":
	return "��ɽ��";
	break;
case "scholar":
	if( age < 50 ) return "���๫";
	else return "�Ϸ�����";
	break;
default:
	if( age < 18 ) return "���Сү��";
	else if( age < 50 ) return "��ү��";
	else return "��үү��";
	break;
			}
	}
}
string query_self_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (this_player()->query("gender")) {
        case "Ů��" :
                if (a1 >= a2)
                        return "�����";
                else
                        return "С����";
                break;
        default :
                if (a1 >= a2)
                        return "������";
                else
                        return "С����";
        }


	return "����rankd.c -> query_self_close()\n";
}

string query_close(object ob)
{
        int a1, a2;

        if (objectp(ob))
        {
                if (a2 = (int)ob->query("mud_age"))
                {
                        a1 = this_player()->query("mud_age");
                } else
                {
                        a1 = this_player()->query("age");
                        a2 = ob->query("age");
                }
        } else
        {
                a1 = this_player()->query("age");
                a2 = 0;
        }

        switch (ob->query("gender")) {
        case "Ů��" :
                if (a1 >= a2)
                        return "����";
                else
                        return "���";
                break;
        default :
                if (a1 >= a2)
                        return "�ܵ�";
                else
                        return "���";
        }
}
string imud_query_self_close(object ob,int age,string gender)
{
        int a1, a2;
	if (objectp(ob))
	{
		a1=ob->query("age");
		a2=age;
	} 
	else 
	{	
       	 	a1 = this_player()->query("age");
       	 	a2 = 0;
	}
        switch (gender) {
        case "Ů��" :
                if (a1 >= a2)
                        return "�����";
                else
                        return "С����";
                break;
        default :
                if (a1 >= a2)
                        return "������";
                else
                        return "С����";
	}
}
string imud_query_close(object ob,int age,string gender)
{
        int a1, a2;

	if (objectp(ob))
	{
		a1=ob->query("age");
		a2=age;
	} else 
	{	
	 	a1 = this_player()->query("age");
	 	a2 = 0;
	}
							
        switch (gender) {
        case "Ů��" :
                if (a1 >= a2)
                        return "����";
                else
                        return "���";
                break;
        default :
                if (a1 >= a2)
                        return "�ܵ�";
                else
                        return "���";
        }
}

