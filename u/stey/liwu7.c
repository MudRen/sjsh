inherit NPC;
#include <ansi.h>
//int give_bonnet();
int give_newbie();
int give_family();
int give_51liwu();
int give_buchang();
//int give_dan1();
int answer_me();

void create()
{
         set_name("СС����", ({"xiao caishen","caishen"}));
   set ("long", @LONG
���������︺�����ҷ���������(gift)��newbie�����������family���ģ�
�����ϴ�����ʦ���ڣ�bonnet������ҸϿ�����Ҫ��ask���ɡ�
LONG);
           set("gender", "����");
        set("title",HIY"�������"NOR);
        set("age", 20);
        set("per", 40);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("inquiry", ([
            "bonnet"    : "��ʦ���ڷ����ˣ�����ô�������ⶼ��֪����",
            "newbie"    :(:give_newbie:),
            "gift"    :(:give_newbie:),
            "����"    :(:give_newbie:),
            "family"    :(:give_family:),
//            "�𱦱����տ���"    :(:give_dan1:),
            "��������"  :(:give_newbie:),
//            "��������"  :(:give_51liwu:),
            "��������"  : (:give_51liwu:),
            "��һ����"  : (:give_51liwu:),
            "��������"  :(:give_family:),
            "����"    :(:give_buchang:),
            "��ʦ����"  : "��ʦ���ڷ����ˣ�����ô�������ⶼ��֪����",
            "name"      :(:answer_me:),
            "�𱦱�"  : "�𱦱���ס�����ڣ��пտ��Դ�绰��tel��0755-6888808",
            "stey" : "stey���Ǳ�����������ô�������ⶼ��֪����",
            "flydance" : "flydance���Ƿ��谡�����Ǻ���ʦ������ô�������ⶼ��֪����",
            "admin" : "admin������������ʦ��������ô�������ⶼ��֪����",
            "calvin" : "calvin�����������������ʦ��������ô�������ⶼ��֪����",
//            "corpsed" : "corpsed��������Ĵ���ʦ���������ⶼ��֪�����찡��",
//           "С�ݹ�" : "���������С�ݹ�,����QQ5765442!",
]));
        setup();
        carry_object("/d/lingtai/obj/faguan")->wear();
}


int answer_me()
{
        command("say С���ұ��㣡�ٺ� ��\n");
        return 1;
}


int give_51liwu()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                command("say ʲôСèС��Ҳ��Ҫ�����");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") < 150000 ){
                command("hammer "+who->query("id") );
                command("say ����ѧ��ô��ȵ�15����ѧ�������㲻���Ǵ��װѣ�");
                return 1;
         }

         if (this_player()->query("liwuu") > 0 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ��һ������ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
        who->add("balance",2000000); 
        who->add("daoxing",100000);
        who->add("force",200);
        who->add("mana",200);
 //       who->add("maximum_force",200);
//        who->add("max_mana",200);
//        who->add("max_force",200);
//      who->add("maximum_mana",200);
        who->add("potential",20000);
        who->set("liwuu",1);
        if (this_player()->query("age") > 24 ){
        who->add("mud_age",-500000);	
         message_vision("$N����$n˵������ϲ���ֱ��С����!\n",this_object(),this_player());
                                                   }
                              
message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",this_object(),this_player());
        command("tell "+who->query("id")+" ��ĵ�����������ʮ��! ���Ǳ��������20000��\n");
        command("chat ��ϲ��ϲ��"+who->query("name")+"�õ�����һ�����\n",);
        command("say ���������backup!\n");
        return 1;
}

int give_newbie()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                command("say ʲôСèС��Ҳ��Ҫ�����");
                command("qi");
                return 1;
        }

         if (who->query("combat_exp") > 40000 ){
                command("hammer "+who->query("id") );
                command("say �㶼��ô�����˻�����ôһ��С����ô��");
                return 1;
         }

         if (this_player()->query("lucky") > 0 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ��������ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
         
        who->add("combat_exp",20000);
        who->add("daoxing",20000);
        who->add("force",400);
        who->add("mana",400);
        who->add("maximum_force",400);
        who->add("max_mana",400);
        who->add("max_force",400);
        who->add("maximum_mana",400);
        who->add("balance",10000);
        who->add("potential",20000);
        who->set("lucky",1);
message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
        ��ĵ��������˶�ʮ��!\n
        ���Ǳ��������20000��\n
        ��������400�������ͷ�����\n");
        command("chat ��ϲ��ϲ��"+who->query("name")+"�õ����������\n");
        return 1;
}
int give_family()
{
        object who=this_player();
        string family;
        family=who->query("family/family_name");
        if (!userp(who))
        {
                command("heng");
                command("say ʲôСèС��Ҳ��Ҫ�����");
                command("qi");
                return 1;
        }
        if (this_player()->query("lucky") > 1 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ��������ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
        if (who->query("combat_exp") > 40000 ) {
                        command("hammer "+who->query("id") );
                command("say �㶼��ô�����˻�����ôһ��С����ô��");
                return 1;
         }
        if ( family == 0 )
        {
                command("heng");
                command("say "+who->query("name")+"�㻹����ȥ��ʦ�ɣ���ʦ֮ǰ�������\nhelp menpai������������Ե���ĸ������ɽ��ܡ�\n");
                return 1;
        }
        switch(family) {
                case "����ɽ���Ƕ�":

who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("spells",50);
who->set_skill("literate",50);
who->set_skill("parry",50);
who->set_skill("liangyi-sword",50);
who->set_skill("stick",50);
who->set_skill("dao",50);
who->set_skill("puti-zhi",50);
who->set_skill("qianjun-bang",50);
who->set_skill("wuxiangforce",50);
who->set_skill("unarmed",50);
who->set_skill("jindouyun",50);
who->set_skill("sword",50);
break;
                case "��ѩɽ":

who->set_skill("literate",50);
who->set_skill("dodge",50);
who->set_skill("force",50);
who->set_skill("spells",50);
who->set_skill("parry",50);
who->set_skill("ningxie-force",50);
who->set_skill("dengxian-dafa",50);
who->set_skill("throwing",50);
who->set_skill("unarmed",50);
who->set_skill("xiaoyaoyou",50);
who->set_skill("blade",50);
who->set_skill("bingpo-blade",50);
who->set_skill("cuixin-zhang",50);
who->set_skill("sword",50);
who->set_skill("bainiao-jian",50);
break;
                case "�¹�":     
who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("unarmed",50);
who->set_skill("literate",50);
who->set_skill("parry",50);
who->set_skill("spells",50);
who->set_skill("sword",50);
who->set_skill("snowsword",50);
who->set_skill("moonshentong",50);
who->set_skill("moondance",50);
who->set_skill("moonforce",50);
who->set_skill("whip",50);         
who->set_skill("jueqingbian",50);  
break;                             
               case "����ɽ":      
               case "��һ��":      
               case "������":
               case "��ħ��":
               case "��ʬ��":
               case "�׵���":
who->set_skill("dodge",50);
who->set_skill("zhaoyangbu",50);
who->set_skill("sword",50);
who->set_skill("huxiaojian",50);
who->set_skill("unarmed",50);
who->set_skill("huxiaoquan",50);
who->set_skill("liushenjue",50);
who->set_skill("stick",50);
who->set_skill("tianyaofa",50);
who->set_skill("literate",50);
who->set_skill("force",50);
who->set_skill("huntianforce",50);
who->set_skill("spells",50);
who->set_skill("tianmogong",50);
who->set_skill("blade",50);
who->set_skill("zileidao",50);
who->set_skill("dodge",50);
who->set_skill("zhaoyangbu",50);
who->set_skill("parry",50);
break;
                case "��������":  
who->set_skill("unarmed",50);
who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("parry",50);
who->set_skill("spells",50);
who->set_skill("seashentong",50);
who->set_skill("dragonfight",50);
who->set_skill("dragonforce",50);
who->set_skill("dragonstep",50);
who->set_skill("hammer",50);
who->set_skill("huntian-hammer",50);
who->set_skill("literate",50);
who->set_skill("fork",50);
who->set_skill("fengbo-cha",50);
break;
                case "�Ϻ�����ɽ":  
who->set_skill("force",50);
who->set_skill("parry",50);
who->set_skill("dodge",50);
who->set_skill("unarmed",50);
who->set_skill("spells",50);
who->set_skill("staff",50);
who->set_skill("jienan-zhi",50);
who->set_skill("lotusforce",50);
who->set_skill("lotusmove",50);
who->set_skill("lunhui-zhang",50);
who->set_skill("buddhism",50);
who->set_skill("literate",50);
break;
                case "��˿��":  
who->set_skill("dodge",50);
who->set_skill("unarmed",50);
who->set_skill("parry",50);
who->set_skill("spells",50);
who->set_skill("force",50);
who->set_skill("jiuyin-xinjing",50);
who->set_skill("lanhua-shou",50);
who->set_skill("pansi-dafa",50);
who->set_skill("qingxia-jian",50);
who->set_skill("sword",50);
who->set_skill("literate",50);
who->set_skill("qin",50);
who->set_skill("sword",50);
who->set_skill("chixin-jian",50);
who->set_skill("whip",50);
who->set_skill("yinsuo-jinling",50);
who->set_skill("yueying-wubu",50);
break;
                case "�ݿ�ɽ�޵׶�": 
who->set_skill("force",50);
who->set_skill("spells",50);
who->set_skill("parry",50);
who->set_skill("dodge",50);
who->set_skill("unarmed",50);
who->set_skill("blade",50);
who->set_skill("kugu-blade",50);
who->set_skill("yaofa",50);
who->set_skill("literate",50);
who->set_skill("yinfeng-zhua",50);
who->set_skill("sword",50);
who->set_skill("qixiu-jian",50);
who->set_skill("huntian-qigong",50);
who->set_skill("lingfu-steps",50);
who->set_skill("sword",50);
break;
                case "��ׯ��":  
who->set_skill("parry",50);
who->set_skill("dodge",50);
who->set_skill("unarmed",50);
who->set_skill("spells",50);
who->set_skill("force",50);
who->set_skill("sword",50);
who->set_skill("literate",50);
who->set_skill("taiyi",50);
who->set_skill("zhenyuan-force",50);
who->set_skill("xiaofeng-sword",50);
who->set_skill("baguazhen",50);
who->set_skill("hammer",50);
who->set_skill("fumo-zhang",50);
who->set_skill("staff",50);
who->set_skill("wuxing-quan",50);
who->set_skill("blade",50);
who->set_skill("yange-blade",50);
who->set_skill("sanqing-jian",50);
break;
                case "���޵ظ�":  
who->set_skill("unarmed",50);
who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("parry",50);
who->set_skill("spells",50);
who->set_skill("literate",50);
who->set_skill("ghost-steps",50);
who->set_skill("gouhunshu",50);
who->set_skill("tonsillit",50);
who->set_skill("whip",50);
who->set_skill("hellfire-whip",50);
who->set_skill("sword",50);
who->set_skill("jinghun-zhang",50);
who->set_skill("zhuihun-sword",50);
who->set_skill("stick",50);
who->set_skill("kusang-bang",50);
break;
                case "���ƶ�": 
who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("parry",50);
who->set_skill("literate",50);
who->set_skill("spells",50);
who->set_skill("unarmed",50);
who->set_skill("dali-bang",50);
who->set_skill("fork",50);
who->set_skill("huomoforce",50);
who->set_skill("moshenbu",50);
who->set_skill("moyun-shou",50);
who->set_skill("pingtian-dafa",50);
who->set_skill("yueya-chan",50);
who->set_skill("fork",50);
who->set_skill("huoyun-qiang",50);
who->set_skill("spear",50);
break;
                case "��ɽ����": 
who->set_skill("sword",50);
who->set_skill("literate",50);
who->set_skill("dodge",50);
who->set_skill("force",50);
who->set_skill("parry",50);
who->set_skill("spells",50);
who->set_skill("unarmed",50);
who->set_skill("hunyuan-zhang",50);
who->set_skill("whip",50);
who->set_skill("sevensteps",50);
who->set_skill("taoism",50);
who->set_skill("yujianshu",50);
who->set_skill("zixia-shengong",50);
break;
                case "������": 
who->set_skill("literate",50);
who->set_skill("baguazhou",50);
who->set_skill("force",50);
who->set_skill("dodge",50);
who->set_skill("spells",50);
who->set_skill("parry",50);
who->set_skill("unarmed",50);
who->set_skill("archery",50);
who->set_skill("bawang-qiang",50);
who->set_skill("changquan",50);
who->set_skill("lengquan-force",50);
who->set_skill("mace",50);
who->set_skill("spear",50);
who->set_skill("wusi-mace",50);
who->set_skill("xuanyuan-archery",50);
who->set_skill("yanxing-steps",50);
break;
        default:
                command("heng");
                command("say "+who->query("name")+"�㻹����ȥ��ʦ�ɣ���ʦ֮ǰ�������\nhelp menpai������������Ե���ĸ������ɽ��ܡ�\n");
                return 1;
}       
        who->set("lucky",2);
        command("nod "+who->query("id") );
        command("chat "+family+"����"+who->query("name")+"�õ������ɽ�����ϣ���Ժ��Ϊ���������⡣\n");
        return 1;
}
/*
int give_bonnet()
 {
        object bonnet;
        object who=this_player();
        bonnet=new("/d/lingtai/obj/faguan.c");
        bonnet->move(who);
        
        message_vision("$N�߶����µĴӰ����ó�һ����ʦ���ڡ�\n$N��$nһ����ʦ���ڡ�\n",this_object(),this_player());
//who->set("yudian/bonnet","got");
 return 1;
} 


void init()
{
    call_out("greeting", 1, this_player());
    ::init();
}
*/

void greeting(object who) {
if( who->query("combat_exp") < 1000)
        tell_object(who,"СС�������ĸ����㣺��������Ҫ����Ŷ(ask)(l xiao caishen)��\n");
        tell_object(who,"СС�������ĸ����㣺��������Ҫ��������Ŷ(ask caishen about family)��\n");
}
/*
int give_dan1()
 {
 	object who=this_player();
 	object dan;
        dan=new("/u/stey/obj/dan1.c");
        if (this_player()->query("dann") > 0 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ��������������ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
        
        dan->move(who);
        
        message_vision("$N�߸����˵ĴӰ����ó�һ���������յ���\n$N��$nһ���𱦱����յ���\n",this_object(),this_player());
        who->set("dann",1);
 return 1;
}
*/ 
int give_buchang()
{
        object who=this_player();
        if (!userp(who)){
                command("heng");
                command("say ʲôСèС��Ҳ��Ҫ�����");
                command("qi");
                return 1;
        }
        /*
         if (who->query("combat_exp") < 150000 ){
                command("hammer "+who->query("id") );
                command("say ����ѧ��ô��ȵ�15����ѧ�������㲻���Ǵ��װѣ�");
                return 1;
         }
         */
         if (this_player()->query("age") < 15 ){
                   command("tell "+who->query("id")+" ������䲻��15��û�в�����\n");  
                     return 1;
                     }  
         if (this_player()->query("liwun") > 0 ){
         message_vision("$N����$n����һ��������Ͳ����ˣ�\n",this_object(),this_player());
                command("hammer "+who->query("id") ); 
                command("say ����ֻ��һ�Σ�����Ͳ����ˣ�\n");
        return 1;
        }
//        who->add("balance",2000000); 
//        who->add("daoxing",100000);
//       who->add("force",200);
//       who->add("mana",200);
 //       who->add("maximum_force",200);
//        who->add("max_mana",200);
//        who->add("max_force",200);
//      who->add("maximum_mana",200);
        who->add("potential",10000);
        who->set("liwun",1);

//        who->add("mud_age",-500000);	

message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",this_object(),this_player());

//        command("chat ��ϲ��ϲ��"+who->query("name")+"�õ�����һ�����\n",);
        command("say ��õ�10000qn�����ˣ����������backup!\n");
        return 1;
}
