inherit NPC;
#include <ansi.h>
//int give_bonnet();
int give_newbie();
int give_family();
//int give_51liwu();
//int give_dan1();
int answer_me();

void create()
{
                  set_name(""HIC"��С������"NOR"", ({"npc peaceful", "npc"})); 
   set ("long", @LONG
���������︺�����ҷ���������(gift)��newbie�����������family���ģ�
�����ϴ�����ʦ���ڣ�bonnet������ҸϿ�����Ҫ��ask���ɡ�
LONG);
           set("gender", "Ů��");
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
  //            "��С���������տ���"    :(:give_dan1:),
            "��������"  :(:give_newbie:),
//            "��������"  :(:give_51liwu:),
            "��������"  : "���첻��ʲô���հѣ�����Űѣ�",
//            "��һ����"  : "��һ�ڶ�������ô���ˣ���̫���ˣ�",
//            "��һ����"  : (:give_51liwu:),
            "��������"  :(:give_family:),
//            "��ʦ����"  : "��ʦ���ڷ����ˣ�����ô�������ⶼ��֪����",
            "name"      :(:answer_me:),
              "��С������"  : "��������ܹ�,���е����鶼����������ס���ൺ��QQ122738350",
            "huage" : "huage���ǻ��簡������ô�������ⶼ��֪����",
            "admin" : "admin������������ʦ��������ô�������ⶼ��֪����",
]));
        setup();
        carry_object("/d/lingtai/obj/faguan")->wear();
}


int answer_me()
{
        command("say С���ұ��㣡�ٺ� ��\n");
        return 1;
}


/*
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
*/

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
/*
 if (who->query("combat_exp") < 7000){
 command("sigh "+who->query("id") );
command("say ����Ҫ���������Ҫ�г��ģ������������㿴�������ѧ������7000!");
                return 1;
              }
*/

         if (this_player()->query("lucky") > 0 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ��������ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
         
          who->add("combat_exp",100000);
          who->add("daoxing",100000);
        who->add("force",400);
          who->add("mana",400);
          who->add("maximum_force",400);
        who->add("max_mana",400);
        who->add("max_force",400);
          who->add("maximum_mana",400);
        who->add("potential",100000);
        who->set("lucky",1);
message_vision("$N����$n���ص�Ц��Ц��$n�������巢�����ҵı仯����ʱ�ε��ڵء�\n",this_object(),this_player());
        command("tell "+who->query("id")+" 
        ��ĵ���������һ����!\n
          ���Ǳ��������100000��\n
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
        if (this_player()->query("lucky1") > 0 ){
         message_vision("$N����$n����һ����\n",this_object(),this_player());
                command("say ��������ֻ��һ�ݣ�����Ͳ����ˣ�\n");
        return 1;
        }
/*
        if (who->query("combat_exp") > 40000 ) {
                        command("hammer "+who->query("id") );
                command("say �㶼��ô�����˻�����ôһ��С����ô��");
                return 1;
         }
*/
 if (who->query("combat_exp") < 10000 ){
 command("sigh "+who->query("id") );
command("say ��ȥ����������!");
                return 1;
              }
        if ( family == 0 )
        {
                command("heng");
                command("say "+who->query("name")+"�㻹����ȥ��ʦ�ɣ���ʦ֮ǰ�������\nhelp menpai�����������񻰡��ĸ������ɽ��ܡ�\n");
                return 1;
        }
        switch(family) {
                case "����ɽ���Ƕ�":
  who->set_skill("force",60);
  who->set_skill("dodge",60);
who->set_skill("spells",60);
who->set_skill("literate",60);
who->set_skill("parry",60);
who->set_skill("liangyi-sword",60);
who->set_skill("qianjun-bang",60);
who->set_skill("stick",60);
who->set_skill("dao",60);
who->set_skill("puti-zhi",60);
who->set_skill("qianjun-bang",60);
who->set_skill("wuxiangforce",60);
who->set_skill("unarmed",60);
who->set_skill("jindouyun",60);
who->set_skill("sword",60);
break;
          case "��ս�":
who->set_skill("force",60);
who->set_skill("piaoyun-zhang",60);
who->set_skill("dodge",60);
who->set_skill("unarmed",60);
who->set_skill("literate",60);
who->set_skill("parry",60);
who->set_skill("spells",60);
who->set_skill("sword",60);
who->set_skill("xiaoyao-sword",60);
who->set_skill("baimofa",60);
who->set_skill("heimofa",60);
who->set_skill("shanbishu",60);
who->set_skill("mtl-force",60);
who->set_skill("throwing",60);
who->set_skill("shouya-force",60);
who->set_skill("blade",60);
who->set_skill("tianlang-blade",60);  
break;
                case "��ѩɽ":

who->set_skill("literate",60);
who->set_skill("dodge",60);
who->set_skill("force",60);
who->set_skill("spells",60);
who->set_skill("parry",60);
who->set_skill("ningxie-force",60);
who->set_skill("dengxian-dafa",60);
who->set_skill("throwing",60);
who->set_skill("unarmed",60);
who->set_skill("xiaoyaoyou",60);
who->set_skill("blade",60);
who->set_skill("bingpo-blade",60);
who->set_skill("cuixin-zhang",60);
who->set_skill("sword",60);
who->set_skill("bainiao-jian",60);
break;
                case "�¹�":     
who->set_skill("force",60);
who->set_skill("dodge",60);
who->set_skill("unarmed",60);
who->set_skill("literate",60);
who->set_skill("parry",60);
who->set_skill("spells",60);
who->set_skill("sword",60);
who->set_skill("snowsword",60);
who->set_skill("moonshentong",60);
who->set_skill("moondance",60);
who->set_skill("moonforce",60);
who->set_skill("blade",60);         
who->set_skill("baihua-zhang",60);  
who->set_skill("xuanhu-blade",60);  
break;                             
               case "����ɽ":      
               case "��һ��":      
               case "������":
               case "��ħ��":
               case "��ʬ��":
               case "�׵���":
who->set_skill("dodge",60);
who->set_skill("zhaoyangbu",60);
who->set_skill("sword",60);
who->set_skill("huxiaojian",60);
who->set_skill("unarmed",60);
who->set_skill("huxiaoquan",60);
who->set_skill("liushenjue",60);
who->set_skill("stick",60);
who->set_skill("tianyaofa",60);
who->set_skill("literate",60);
who->set_skill("force",60);
who->set_skill("huntianforce",60);
who->set_skill("spells",60);
who->set_skill("tianmogong",60);
who->set_skill("blade",60);
who->set_skill("zileidao",60);
who->set_skill("dodge",60);
who->set_skill("zhaoyangbu",60);
who->set_skill("parry",60);
break;
                case "��������":  
who->set_skill("unarmed",60);
who->set_skill("force",60);
who->set_skill("dodge",60);
who->set_skill("parry",60);
who->set_skill("spells",60);
who->set_skill("seashentong",60);
who->set_skill("dragonfight",60);
who->set_skill("dragonforce",60);
who->set_skill("dragonstep",60);
who->set_skill("hammer",60);
who->set_skill("huntian-hammer",60);
who->set_skill("literate",60);
who->set_skill("fork",60);
who->set_skill("fengbo-cha",60);
break;
                case "�Ϻ�����ɽ":  
who->set_skill("force",60);
who->set_skill("parry",60);
who->set_skill("dodge",60);
who->set_skill("unarmed",60);
who->set_skill("spells",60);
who->set_skill("staff",60);
who->set_skill("jienan-zhi",60);
who->set_skill("lotusforce",60);
who->set_skill("lotusmove",60);
who->set_skill("lunhui-zhang",60);
who->set_skill("buddhism",60);
who->set_skill("literate",60);
break;
                case "��˿��":  
who->set_skill("dodge",60);
who->set_skill("unarmed",60);
who->set_skill("parry",60);
who->set_skill("spells",60);
who->set_skill("force",60);
who->set_skill("jiuyin-xinjing",60);
who->set_skill("lanhua-shou",60);
who->set_skill("pansi-dafa",60);
who->set_skill("qingxia-jian",60);
who->set_skill("literate",60);
who->set_skill("qin",60);
who->set_skill("sword",60);
who->set_skill("chixin-jian",60);
who->set_skill("whip",60);
who->set_skill("yinsuo-jinling",60);
who->set_skill("yueying-wubu",60);
break;
                case "�ݿ�ɽ�޵׶�": 
who->set_skill("force",60);
who->set_skill("spells",60);
who->set_skill("parry",60);
who->set_skill("dodge",60);
who->set_skill("unarmed",60);
who->set_skill("blade",60);
who->set_skill("kugu-blade",60);
who->set_skill("yaofa",60);
who->set_skill("literate",60);
who->set_skill("yinfeng-zhua",60);
who->set_skill("qixiu-jian",60);
who->set_skill("huntian-qigong",60);
who->set_skill("lingfu-steps",60);
who->set_skill("sword",60);
break;
                case "��ׯ��":  
who->set_skill("parry",60);
who->set_skill("dodge",60);
who->set_skill("unarmed",60);
who->set_skill("spells",60);
who->set_skill("force",60);
who->set_skill("sword",60);
who->set_skill("literate",60);
who->set_skill("taiyi",60);
who->set_skill("zhenyuan-force",60);
who->set_skill("xiaofeng-sword",60);
who->set_skill("baguazhen",60);
who->set_skill("hammer",60);
who->set_skill("fumo-zhang",60);
who->set_skill("kaishan-chui",60);
who->set_skill("staff",60);
who->set_skill("wuxing-quan",60);
who->set_skill("blade",60);
who->set_skill("yange-blade",60);
who->set_skill("sanqing-jian",60);
break;
                case "���޵ظ�":  
who->set_skill("unarmed",60);
who->set_skill("force",60);
who->set_skill("dodge",60);
who->set_skill("parry",60);
who->set_skill("spells",60);
who->set_skill("literate",60);
who->set_skill("ghost-steps",60);
who->set_skill("hellfire-whip",60);
who->set_skill("gouhunshu",60);
who->set_skill("tonsillit",60);
who->set_skill("whip",60);
who->set_skill("hellfire-whip",60);
who->set_skill("sword",60);
who->set_skill("jinghun-zhang",60);
who->set_skill("zhuihun-sword",60);
who->set_skill("stick",60);
who->set_skill("kusang-bang",60);
break;
                case "��������": 
who->set_skill("baiyun-sword",60);
who->set_skill("dodge",60);
who->set_skill("force",60);
who->set_skill("lingxiyizhi",60);
who->set_skill("literate",60);
who->set_skill("parry",60);
who->set_skill("piaoxiang",60);
who->set_skill("spells",60);
who->set_skill("sword",60);
who->set_skill("tianjijue",60);
who->set_skill("unarmed",60);
who->set_skill("wuji-force",60);
break;
                case "���ƶ�": 
who->set_skill("force",60);
who->set_skill("dodge",60);
who->set_skill("parry",60);
who->set_skill("literate",60);
who->set_skill("spells",60);
who->set_skill("unarmed",60);
who->set_skill("dali-bang",60);
who->set_skill("fork",60);
who->set_skill("huomoforce",60);
who->set_skill("moshenbu",60);
who->set_skill("moyun-shou",60);
who->set_skill("stick",60);
who->set_skill("pingtian-dafa",60);
who->set_skill("yueya-chan",60);
who->set_skill("huoyun-qiang",60);
who->set_skill("spear",60);
break;
                case "��ɽ����": 
who->set_skill("sword",60);
who->set_skill("literate",60);
who->set_skill("dodge",60);
who->set_skill("force",60);
who->set_skill("parry",60);
who->set_skill("spells",60);
who->set_skill("unarmed",60);
who->set_skill("hunyuan-zhang",60);
who->set_skill("whip",60);
who->set_skill("sevensteps",60);
who->set_skill("taoism",60);
who->set_skill("yujianshu",60);
who->set_skill("zixia-shengong",60);
break;
                case "������": 
who->set_skill("literate",60);
who->set_skill("baguazhou",60);
who->set_skill("force",60);
who->set_skill("dodge",60);
who->set_skill("spells",60);
who->set_skill("parry",60);
who->set_skill("unarmed",60);
who->set_skill("archery",60);
who->set_skill("bawang-qiang",60);
who->set_skill("changquan",60);
who->set_skill("lengquan-force",60);
who->set_skill("mace",60);
who->set_skill("spear",60);
who->set_skill("wusi-mace",60);
who->set_skill("xuanyuan-archery",60);
who->set_skill("yanxing-steps",60);
break;
                        case "��������":  
     who->set_skill("literate",60); 
     who->set_skill("tianjijue",60); 
     who->set_skill("force",60); 
     who->set_skill("dodge",60); 
     who->set_skill("spells",60); 
     who->set_skill("parry",60); 
     who->set_skill("unarmed",60); 
    who->set_skill("sword",60); 
     who->set_skill("baiyun-sword",60); 
     who->set_skill("lingxiyizhi",60); 
     who->set_skill("wuji-force",60); 
     who->set_skill("piaoxiang",60); 
    break; 
                             case "������":   
          who->set_skill("literate",60);  
          who->set_skill("mahayana",60);  
          who->set_skill("force",60);  
          who->set_skill("dodge",60);  
          who->set_skill("spells",60);  
          who->set_skill("parry",60);  
          who->set_skill("unarmed",60);  
         who->set_skill("sword",60);  
            who->set_skill("huifeng-sword",60);  
          who->set_skill("jinding-zhang",60);  
          who->set_skill("emeiforce",60);  
          who->set_skill("zhutian-bu",60);  
    break; 
                             case "������":   
          who->set_skill("literate",60);  
          who->set_skill("force",60);  
          who->set_skill("dodge",60);  
          who->set_skill("spells",60);  
          who->set_skill("parry",60);  
          who->set_skill("unarmed",60);  
          who->set_skill("sword",60);  
          who->set_skill("banruo-zhang",60);  
          who->set_skill("chanzong",60);  
          who->set_skill("shaolin-shenfa",60);  
          who->set_skill("shaolin-sword",60);  
          who->set_skill("yijinjing",60);  
          who->set_skill("zui-gun",60);  
          who->set_skill("stick",60);  
    break; 
                                  case "����ɽ���鶴":    
               who->set_skill("literate",60);   
               who->set_skill("force",60);   
              who->set_skill("dodge",60);   
              who->set_skill("spells",60);   
               who->set_skill("parry",60);   
               who->set_skill("unarmed",60);   
               who->set_skill("sword",60);   
              who->set_skill("kaitian-zhang",60);   
              who->set_skill("yuxu-spells",60);   
              who->set_skill("lingyunbu",60);   
              who->set_skill("xuanzong-force",60);   
              who->set_skill("wugou-jian",60);   
       break; 
              case "��������":  
   who->set_skill("force",60);
   who->set_skill("spells",60);
   who->set_skill("dodge",60);
   who->set_skill("parry",60);
   who->set_skill("unarmed",60);
   who->set_skill("literate",60);
   who->set_skill("guixi-force",60);
   who->set_skill("renshu",60);
   who->set_skill("fengyu-piaoxiang",60);
   who->set_skill("huoxin-sword",60);
   who->set_skill("sword",60);
   who->set_skill("huoxin-sword",60);
   who->map_skill("force", "guixi-force");
   who->map_skill("spells", "renshu");
     break; 

        default:
                command("heng");
                command("say "+who->query("name")+"�㻹����ȥ��ʦ�ɣ���ʦ֮ǰ�������\nhelp menpai�����������񻰡��ĸ������ɽ��ܡ�\n");
                return 1;
}       
        who->set("lucky1",1);
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
          tell_object(who,"��С���������ĸ����㣺��������Ҫ����Ŷ(ask)(l npc peaceful)��\n");
        tell_object(who,"��С���������ĸ����㣺��������Ҫ��������Ŷ(ask peaceful about family)��\n");
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
        
          message_vision("$N�߸����˵ĴӰ����ó�һ���������յ���\n$N��$nһ����С���������յ���\n",this_object(),this_player());
        who->set("dann",1);
 return 1;
}
*/ 
