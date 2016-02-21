#include <ansi.h>
inherit ITEM;
inherit __DIR__"skill_reward";

void create()
{
        set_name(RED"�ż�"NOR, ({ "secret letter","xin","letter" }));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long",
                        "����һ����ƹ������������ź���\n");
                set("value", 1);
                set("material", "paper");
         }
        set("no_give","���Ǵ��Ʊ��µ��ź�,��ô�������ˣ�\n");
        set("no_sell","���Ǵ��Ʊ��µ��ź�,��ô������\n");
}

void init()
{       
        call_out("dest",(random(100)+900));
        add_action("do_send", "songxin");
        add_action("do_look", "kan");
        add_action("do_look", "chakan");
}

int do_look(string arg)
{
        int now_time, time;
        object me;

        me = this_player();
        now_time =time() - me->query_temp("songxin_time"); 
        time = 900;

        if(!arg) return 0;
        if( (arg=="letter"||arg=="xin")&&me->query_temp("datang_songxin")) {
                write(
                        "\n����һ���ɴ��ƹ����������ż�������д��"
                        HIR" ��"+me->query_temp("songxin_target_name")+"�� ������\n"NOR);
                if(now_time >0 && now_time < time/8) write("�������г����ʱ��ȥ���š�\n");
                else if(now_time < time/4 ) write("�Ѿ���ȥһС��ʱ���ˡ�\n");
                else if(now_time < time/2 ) write("�㻹��һ���ʱ��ȥ���š�\n");
                else if(now_time < time*3/4 ) write("���ʱ���Ѿ������ˡ�\n");
                else write("ʱ�佫�������񼴽�ʧ�ܡ�\n");
        }else{
        if( (arg=="letter"||arg=="xin")&&!me->query_temp("datang_songxin")) 
        write("����һ����ƹ������������ź���\n");
         }
                return 1;

}

int do_send(string arg)
{
        int i,j,exp,pot,number,silver,num;
        object me,target;
        string t_name,msg,msg1,skill;

        me=this_player();
        number = (int)me->query("combat_exp");
          for(i=0;i*i*i <(number/10);i++);

        if(!arg) 
               {
          me->add_temp("songxin/shibai",30);
           return notify_fail("��Ļ���Ǳ�ܺ͵��м�����ʮ�㡣\n��Ҫ�͸�˭��\n");
            }
        if(!objectp(target = present(arg, environment(me))) || !target) 
           {
           me->add_temp("songxin/shibai",30);
               return notify_fail("��Ļ���Ǳ�ܺ͵��м�����ʮ�㡣\n������㣬��Ҫ���ŵ��˲������\n");
           }
        t_name = target->query("name");
 
        if(userp(target) || me->query("id") != target->query("target_id"))
          {
          me->add_temp("songxin/shibai",30);
           return notify_fail("��Ļ���Ǳ�ܺ͵��м�����ʮ�㡣\n�ٺ٣������ף���\n");
           }
        if (!present("secret letter", me) )
           return notify_fail("������û��Я���ż���\n"); 
        if (!me->query_temp("datang_join"))
           return notify_fail(t_name+"�����㲻�Ǵ���ʹ�ߣ���ô���ʹ��Ʊ��µ��Ÿ��ң�\n");
        if (!me->query_temp("datang_songxin") || me->query("id") !=query("target_id") )
           return notify_fail(t_name+"�������Ǵ��ƻʹ����Խ�����,Ҫ���͵ģ�\n���ǲ��Ǵӱ������������ģ�\n");
        if(me->query_temp("songxin_target_name") != t_name) 
           return notify_fail(t_name+"��������Ų��Ǹ��ҵģ����ǲ����ʹ��ˣ�\n");
        message_vision(HIY"$N����һ�Ѷ�ͷ�ĺ����ӻ����ͳ��Ž���$n˵�������Ǵ��Ʊ���\n�������͸������ţ������պá�\n"NOR, me, target);
        message_vision("$N������$nһ���š�\n",me, target);
        message_vision(HIY "$N�ӹ��ſ��˿������˵�ͷ˵������λ"+RANK_D->query_respect(me)+"�������ˡ�\n"NOR, target, me);
        
        if(number<300000) {
            exp=3500+number/600;
            pot=2000+number/3000;
        } else if(number<3000000) {
            exp=4000+number/6000;
            pot=2500+number/60000;
        } else if(number<30000000) {
            exp=4500+number/60000;
            pot=3000+number/600000;
        } else {
            exp=5000;
            pot=3500;
        }
       
         exp -= me->query_temp("songxin/shibai");
         pot -= me->query_temp("songxin/shibai");

     if(me->query_temp("npc_kill"))
       {
       me->add_temp("songxin/datang_job",1);
       me->add("songxin/job",1);
       num = (int)me->query_temp("songxin/datang_job");
   pot=150+pot*num/20;
      exp=250+exp*num/20;
       silver = (random(i)+num);
       }
      else
       {
       me->delete_temp("songxin/datang_job");
       me->delete("songxin/job");
         pot = pot/15 + random(100);
        exp = exp/15 + random(200);
         silver = random(i);
       }

       me->add("potential",pot);
       me->add("combat_exp",exp);
       me->add("balance",(silver*100));
       me->add("songxin/potential",pot);
       me->add("songxin/combat_exp",exp);
       me->add("songxin/silver",silver);
       me->add("songxin/number",1);
      
       tell_object(me,HIW"�ã��������,�������£�\n" + 
                       "��ĵ���������"+COMBAT_D->chinese_daoxing(exp)+"\n" +
                       "���Ǳ��������"+chinese_number(pot) + "��\n"+
                       "��Ĵ��������"+chinese_number(silver)+"������\n"
                       NOR);

       msg="Ϊ���Ʊ������Ÿ�"+me->query_temp("songxin_where")+"��"+me->query_temp("songxin_target_name")+"��\n���exp��"+exp+"��pot��"+pot+ "��silver��"+silver+"��";

       if (me->query("songxin/job") > 24) 
       {
       me->delete("songxin/job");
       if(number <= 300000)    j=2+random(4);
       if(number > 300000 && number <= 6000000)   j=3+random(4);
       if(number > 6000000 && number <= 18000000) j=4+random(4);
       if(number > 18000000)              j=5+random(4);
       me->add("potential",5000+250*j);
       me->add("combat_exp",5000+250*j);
       me->add("songxin/job1",1);
       me->add("songxin/potential",5000+250*j);
       me->add("songxin/combat_exp",5000+250*j);
       msg +="������ʮ������⽱����exp��" + (5000+250*j) + "��pot��" + (5000+250*j) + "��\n";
       tell_object(me,"��������ʮ���Ϊ���Ʊ������ţ�������\n����"+ COMBAT_D->chinese_daoxing(5000+250*j)+ "��\nǱ��"+chinese_number(5000+250*j) + "�㡣\n");
       }

       if (me->query_temp("songxin/datang_job") > 8) 
       {
       me->delete_temp("songxin/datang_job");
       skill=give_reward(me);
       msg+= "and rewarded 1 lvl of "+skill+".\n";
       if(skill != "none")
                 {
       me->add("songxin/skill",1);
       msg1="��˵"+ me->query("name")+ "�����Ŵ�Ϊ���Ʊ������ţ��ؽ���һ��"+ to_chinese(skill)+ "��\n";
       CHANNEL_D->do_channel(this_object(),"rumor",msg1);
                }
       }
      else msg+= "and rewarded 1 lvl of "+skill+".\n";

      MONITOR_D->report_quests_object_msg(me, msg);
  
      me->delete_temp("datang_songxin");
      me->delete_temp("songxin_time");
      me->delete_temp("npc_kill");       
      me->delete_temp("songxin_target_name");
      me->delete_temp("songxin_target_id");
      me->delete_temp("songxin_where"); 
      me->delete_temp("kill_target_name");
      me->delete_temp("kill_target_id");
      me->delete_temp("kill_where");  
      me->delete_temp("songxin/shibai");  
      destruct(target);
      destruct(this_object());
      return 1;
}

void dest()
{
      tell_object(this_player(),"���ź�Ȼ������·�ϲ����ˡ�\n");  
      destruct(this_object());
}

