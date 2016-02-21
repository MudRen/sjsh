#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR"�򹬱���"NOR, ({ "zhenggong baowu","baowu"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "һ�����ص��򹬱���,�����칬��Ҫ���򹬷���֮һ��\n");
                set("value", 0);
                set("material", "gold");
		 
         }
}
void init()
{    
	add_action("do_jihui", "jihui");
}

int do_jihui(string arg)
{
        int i,exp,pot,count,base_exp,add_exp;
        object ob,me,*team;
              
		me=this_player();
        ob=this_object();
		if(!arg||arg!="baowu") return notify_fail("��Ҫ����ʲô��\n");
        if(ob->query_temp("host")!= me->query("id")
			||!me->query_condition("zzz_busy")||!me->query_temp("team_count"))
		return notify_fail("����º������û��ϵ��?\n");
		if (!present("zhenyuan baowu",me) )
        return notify_fail("������û���򹬱��\n"); 
        //check ok
		message_vision("$N�ֹ��˼������︽���򹬱��\n"+HIR"ֻ�����䡹��һ�����򹬱�����һ�������������ʧ ��\n"NOR, me);
        count=me->query_temp("team_count");
		if (count<2) count=2;	
        base_exp=1500/count;
		team=me->query_team();
		count=sizeof(team);
		//write("\n"+sprintf("%d",count));
		for(i=0;i<count;i++)
		{ if(team[i]!=0)
		{
			if (team[i]->query_condition("zzz_busy"))
			{if(!team[i]->query("zzz_job_count"))
		     team[i]->set("zzz_job_count",1);
             else
		     team[i]->add("zzz_job_count",1);  
			 add_exp=team[i]->query("zzz_job_count")/10;
		     exp=base_exp+random(200)+add_exp;
		     pot=exp/3+random(100);
             team[i]->add("potential",pot);
             team[i]->add("combat_exp",exp);
			 tell_object(team[i],HIW"�㱻�����ˣ�\n" + 
                       chinese_number(exp) + "��ʵս����\n" +
                       chinese_number(pot) + "��Ǳ��\n"+
                       NOR);
			}
			} 
		}
		  me->delete_temp("team_count");
         	  
		  destruct(this_object());
          return 1;
}

