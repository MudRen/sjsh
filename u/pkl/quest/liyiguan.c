inherit NPC;
#include <ansi.h>

string *dirs1 = ({
"/d/city",
"/d/westway",
"/d/kaifeng",
"/d/lingtai",
"/d/moon",
"/d/gao",
"/d/sea", 
"/d/nanhai", 
"/d/eastway",
"/d/ourhome/honglou", 
"/d/jz",
"/d/shushan",
"/d/shuilian",
"/d/pansi",
"/d/qujing/xuanyuan",
});

string *dirs2 = ({
"/d/xueshan",
"/d/xiaoyao",
"/d/jueqinggu",
"/d/suifeng",
"/d/qujing/wuzhuang", 
"/d/qujing/baotou", 
"/d/qujing/baoxiang", 
"/d/qujing/bibotan",
"/d/qujing/biqiu",
"/d/qujing/chechi",
"/d/qujing/dudi",
"/d/qujing/fengxian",
"/d/qujing/firemount",
"/d/qujing/jilei",
"/d/qujing/jindou",
"/d/qujing/jingjiling",
"/d/qujing/jinping",
"/d/qujing/jisaiguo",
"/d/qujing/maoying",
"/d/qujing/huangfeng",
"/d/qujing/yingjian",
"/d/qujing/sanda",
"/d/qujing/heishui",
"/d/qujing/tuoshi",
"/d/qujing/village",
"/d/qujing/heifeng",
"/d/qujing/shuangcha",
"/d/qujing/liusha",
"/d/qujing/nuerguo",
"/d/qujing/pingding",
"/d/qujing/pansi",
"/d/qujing/tongtian",
"/d/qujing/qilin",
"/d/qujing/huoyun",
"/d/qujing/qinfa",
"/d/qujing/qinglong",
"/d/qujing/tianzhu",
"/d/qujing/wudidong",
"/d/qujing/wuji",
"/d/qujing/xiaoxitian",
"/d/qujing/yinwu",
"/d/qujing/yuhua",
"/d/qujing/zhujie",
"/d/qujing/zhuzi",
"/d/dntg/hgs",
"/d/dntg/sky",
"/d/penglai",
});

string *dirs3 = ({
"/d/death",  
"/d/meishan",
"/d/qujing/lingshan",
});

string ask_job();
string ask_join();
string ask_fangqi();

void create()
{
        set_name("���ǹ�", ({ "liyi guan","liyi","guan","liyiguan" }));
        set("title", "���ƽӴ�����ʹ��");
        set("gender", "����");
        set("age", 33);
        set("str", 27);
        set("long", "���Ż����ķ��Σ�Ӣ�����ˡ�\n");
        set("combat_exp", 400000);
        set("attitude", "peaceful");
        set_skill("unarmed", 100);
        set_skill("force", 100);
        set_skill("whip", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);

        set("max_kee", 900);
        set("force", 900); 
        set("max_force", 900);
        set("max_sen", 900);
        set("inquiry", 
                ([
                 "����"    : (: ask_job :),
                 "songxin" : (: ask_job :),
                 "work"    : (: ask_job :),
                 "job"     : (: ask_job :),
                 "ʹ��"    : (: ask_join :),
                 "shizhe"  : (: ask_join :),
                 "����"    : (: ask_fangqi :),
                 "fangqi"  : (: ask_fangqi :),
                ]));

        set("chat_chance", 10);
        set("chat_msg", ({
                "���ǹ�˵��: ���Ʊ��¹�����������֮ʿ�����������\n",
              }) );

        setup();
}

string ask_fangqi()
{
        object ob = this_player();

           if ((int)ob->query("balance") < 10000)
              return ("��Ĵ������������δ��ɵ�����\n");
          if (!ob->query_temp("datang_songxin"))
              return ("��û�������ŵ�����\n");

        ob->add("balance",-10000);
        ob->delete_temp("datang_songxin");
        ob->delete_temp("songxin_time");
        ob->delete_temp("npc_kill");       
        ob->delete_temp("songxin_target_name");
        ob->delete_temp("songxin_target_id");
        ob->delete_temp("songxin_where"); 
        ob->delete_temp("kill_target_name");
        ob->delete_temp("kill_target_id");
              ob->delete_temp("songxin/datang_job");  
             ob->delete("songxin/job");     
      ob->delete_temp("songxin/shibai");
        ob->delete_temp("kill_where");  

        return ("����û�ã�������鶼�첻����\n");

}

string ask_join()
{
        object ob = this_player();
        string *applied_id;

         if (ob->query("combat_exp")<10000)
                     return ("����书̫�ʲôҲ�����˵ġ�\n");

        if (ob->query_temp("datang_join"))
                return (RANK_D->query_respect(ob) + 
                "�����Ѿ��Ǵ���ʹ���ˡ�\n");
        ob->set_temp("datang_join",1);
        if( pointerp(applied_id = ob->query_temp("apply/id")) && sizeof(applied_id) )
               ob->set_temp("apply/short", ({HIY"����ʹ��"NOR+" "+ob->name()+"("+applied_id[0]+")"}));
        else
               ob->set_temp("apply/short", ({HIY"����ʹ��"NOR+" "+ob->name()+"("+ob->query("id")+")"}));       
       command("look "+ob->query("id"));
        return ("��,������λ" + RANK_D->query_respect(ob) + "����Ϊ���Ʊ������š�\n");

}

string ask_job()
{
       object me,ob,obj,newob,who,who1;
       int i, j, k,l,exp;
       string* dirs,songxin_where,kill_where,name,name1,id,id1;
       mixed*  file, exit;

       ob=this_player();
       me=this_object();
       exp=ob->query("combat_exp");

       if (!ob->query_temp("datang_join"))
          return RANK_D->query_respect(ob) +"���㲻�Ǵ���ʹ�ߣ��˻��Ӻ�˵��";

       if (ob->query_temp("datang_songxin"))
          return ("�㲻���Ѿ��������ŵ������𣿻�����ȥ����\n");

       if (time()-ob->query_temp("songxin_time") < 600)
          return "������ʱû�и��������";

       if (ob->query("combat_exp")<80000)
          return ("��Ĺ��򻹲����������ſ��Ǻ�Σ�յ��£��ҿɲ��ҽ�����������\n");
 
        if(exp<100000) {
            dirs=dirs1;
        } else if(exp<1500000) {
            dirs=dirs1+dirs2;
        } else {
            dirs=dirs1+dirs2+dirs3;
        }

        if( !sizeof(dirs) )  return 0 ;

        i = random(sizeof(dirs));    

        file = get_dir( dirs[i]+"/*.c", -1 );

        if( !sizeof(file) )
               return 0;

       who = new(__DIR__"target_npc");
       who->set("target_id",ob->query("id"));

       ob->set_temp("songxin_target_id", who->query("id"));
       ob->set_temp("songxin_target_name", who->query("name"));
       
        for(k=0;k<30;k++) { 
           j = random(sizeof(file));
           if( file[j][1] > 0 ) 
             {
             newob=load_object(dirs[i]+"/"+file[j][0]);
             if (newob) 
                 {  
                 if(newob->query("no_fight") ||
                       newob->query("no_magic") ||
                       !(exit=newob->query("exits")) ||
                       sizeof(exit)<1)
                       continue;
                 who->move(newob);
                 message_vision("$N���˹�����\n",who);
                  }
           }
        }

       ob->set_temp("songxin_where", environment(who)->query("short"));

       l = random(sizeof(dirs));    

       file = get_dir( dirs[l]+"/*.c", -1 );

       if( !sizeof(file) )
               return 0;

       who1 = new(__DIR__"kill_npc");
       who1->invocation(ob);
         who1->set("target",ob);
       who1->set("target_id",ob->query("id"));

       obj=new(__DIR__"datang_letter");
       obj->set("target_id",ob->query("id"));
       obj->move(who1);
     
         ob->set_temp("kill_target_id", who1->query("id"));
        ob->set_temp("kill_target_name", who1->query("name"));

       for(k=0;k<30;k++) { 
           j = random(sizeof(file));
           if( file[j][1] > 0 ) 
             {
             newob=load_object(dirs[l]+"/"+file[j][0]);
             if (newob) 
                 {  
                 if(newob->query("no_fight") ||
                       newob->query("no_magic") ||
                       !(exit=newob->query("exits")) ||
                       sizeof(exit)<1)
                       continue;
                   who1->move(newob);
                 message_vision("$N���˹�����\n",who1);
                  }
           }
        }

       ob->set_temp("kill_where", environment(who1)->query("short"));
       ob->set_temp("datang_songxin",1);
       ob->set_temp("songxin_time",time());

       songxin_where = environment(who)->query("short");
       name = who->query("name");
       id = who->query("id");
       kill_where = environment(who1)->query("short");
       name1 = who1->query("name");
       id1 = who1->query("id");

switch(random(5)) {
        case 0:
        tell_object(ob,kill_where+"��"+name1+"("+id1+")"+"�ѱ����͸�"+songxin_where+"��"+name+"("+id+")"+"�������ˡ�\n��������ȥ��������顣\n");
        break;
        case 1:
        tell_object(ob,kill_where+"��"+name1+"("+id1+")"+"�ѱ����͸�"+songxin_where+"��"+name+"("+id+")"+"�������ˡ�\n�鷳��ȥ��������顣\n");
        break;
        case 2:
        tell_object(ob,kill_where+"��"+name1+"("+id1+")"+"�ѱ����͸�"+songxin_where+"��"+name+"("+id+")"+"�������ˡ�\n����Ѹ��ȥ��������顣\n");
        break;
        case 3:
        tell_object(ob,kill_where+"��"+name1+"("+id1+")"+"�ѱ����͸�"+songxin_where+"��"+name+"("+id+")"+"�������ˡ�\n��ҪС��ȥ��������顣\n");
        break;
        case 4:
        tell_object(ob,kill_where+"��"+name1+"("+id1+")"+"�ѱ����͸�"+songxin_where+"��"+name+"("+id+")"+"�������ˡ�\n����ȥ���������顣\n");
        break;
        }

       return "���С�ġ�\n";
}
