//����npc
inherit F_VENDOR_SALE;

#include <ansi.h>
int give_wx();
int give_wx2();
int answer_me();

void create()
{
         set_name(HIC"�񱦱�"NOR, ({"baobao"}));
   set ("long", @LONG
���������︺�����ҷ���ѧ�����Ŀɰ����񱦱�����ask baobao about ������
LONG);
           set("gender", "����");
        set("title",HIY"���ÿɰ���"NOR);
        set("age", 28);
        set("per", 40);
        set("attitude", "peaceful");
        set("vendor_goods", ([
                "armor":        "/d/obj/armor/jinjia",
                "spellsbook":    "/d/obj/book/mihou-book.c",
                "sword":    "/u/stey/sttt.c",
                "whip":    "/u/stey/yaowhip1.c",
                "hammer":    "/u/stey/tianhammer.c",
                "fork":    "/u/stey/shenfork.c",
                "spear":    "/u/stey/shenspear.c",
                "stick":    "/u/stey/tianbang.c",
                "qin":    "/u/stey/moqin.c",
                "blade":    "/u/stey/guiblade.c",
                "staff":    "/u/stey/shenstaff.c",
                "parrybook":    "/d/obj/book/parrybook2",
                "forcebook":    "/d/obj/book/forcebook2",
        ]) );
        set("inquiry", ([
            "����"    :(:give_wx:),
            "��ѧ����"    :(:give_wx:),
            "jiangli"    :(:give_wx:),
            "100��"    :(:give_wx2:),
   ]));
        setup();
        carry_object("/d/lingtai/obj/faguan")->wear();
}
int answer_me()
{
        command("say С���ұ��㣡�ٺ� ��\n");
        return 1;
}
int give_wx()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                  command("say ʲôСèС��Ҳ��Ҫ����?");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") < 500000 ){
                command("hammer "+who->query("id") );
                command("say ����Ŭ��Ŭ�����ܿ�����ý����ġ�");
                command("addoil "+who->query("id") );
                return 1;
         }
         if (this_player()->query("jjj") > 0 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ����ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
        who->add("potential",50000);
        who->add("balance",5000000);
        who->add("daoxing",50000);
        who->set("jjj",1);
message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",this_object(),this_player());
        command("tell "+who->query("id")+"
               ���Ǳ��������50000��\n             
               ��ĵ�����������ʮ��!\n 
               �����ڴ��������500gold��\n");
          command("chat ��ϲ��ϲ��"+who->query("name")+"�õ�����ѧ50��Ľ�����\n");
        return 1;                      
}                                      
void init()                            
{                                      
     call_out("greeting", 1, this_player());
      ::init();
               add_action("do_fight", "fight");     
               add_action("do_kill", "kill");       
               add_action("do_cast", "cast");       
               add_action("do_bian","bian");        
               add_action("do_cast", "perform");                           
               add_action("do_steal", "steal");       
               add_action("do_vendor_list", "list");
}                                            
                                             
int do_kill(string arg)                                                       
{                                                                             
        object who = this_player();                                           
        object me = this_object();                                            
                                                                              
        if(!arg || present(arg,environment(me))!=me) return 0;                
                                                                              
        message_vision("$N��$n��в�������ɱ�ң�������ˣ�\n", me, who);    
        return 1;                                                             
} 

int do_bian(string arg)                                                                                                                              
{                                                                        
        object who = this_player();                                      
        object me = this_object();                                       
                                                                         
        if(!arg || present(arg,environment(me))!=me) return 0;           
                                                                         
        message_vision("$N�ٺټ�Ц�˼���������С�����ޣ�\n", me);
        return 1;                                                        
}                                                                        
                       
int do_cast(string arg)                                                                                                                                                         
{                                                                                                      
        object who = this_player();                                                                    
        object me = this_object();                                                                     
        message_vision("$N��$n��в�������ɱ��ʦ��������ˣ�\n", me, who);                             
        return 1;                                                                                      
}                                                                                                      
                                                                             
                                                                                                                                                                                       
int do_fight(string arg)                                                                                                            
{                                                                                                                                   
        object who = this_player();                                                                                                 
        object me = this_object();                                                                                                  
                                                                                                                                    
        if(!arg || present(arg,environment(me))!=me) return 0;                                                                      
                                                                                                                                    
        message_vision("$N��$nҡ��ҡͷ���㲻���Ҷ��֣�����\n", me, who);                                                      
        return 1;                                                                                                                   
}                                                                                                                                   
                                                                                                                                    