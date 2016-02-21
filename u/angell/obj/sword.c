#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
        set_name("�����ý�",({ "jueshi haojian", "jueshi", "sword", "jian" }) );
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 1);
                set("rigidity", 10);
                set("sharpness", 10);
                set("unique", 1);
                set("material", "steel");
                set("weapon_prop/dodge", 5);
                set("weapon_prop/parry", 5);
                set("treasure",1);              
                set("long", "����һ���ĳ�������ȫ���ںڣ����Զ����ݽ�ɽׯ����ɽׯ��������ʦ��ʱ������ɵĽ���֮����\n"); 
                set("wield_msg", "ɲ�Ǽ䣬һ����׳ɽ�ӵĺں磬������ʺ��������һ�㣬���в���գ�۵�΢С��϶��������������ǰ��\n");
                set("unwield_msg", "\n����$N��$n����һֱ����ƥ���������𣬽�$n����ʵʵ�ع���������\n");
        }
        init_sword(500);
        setup();
}

int wield()
{
        object ob = environment();
        object me = this_object();
        mapping weapon_prop;
        object *obj, *inv, weapon;
        int ret, i, j;

        if (ob->query("combat_exp") < 500000 
            || ob->query_str() < 30 || ob->query("max_force") < 3000 
            || ob->query("force") < 2000){
                message_vision(HIY"$N���ָոմ�����$n�Ľ��ѣ�ͻȻһ����������������Խ��д�������$N������Զ��
$nҲ��֮������ϡ�\n"NOR, ob, me);
                ob->receive_damage("qi", 100);
                ob->receive_wound("qi", 50);
                me->move(environment(ob));
                return 0;
                }
       else if (ret=::wield()){
           message_vision(HIB"\nֻ��$N��һ���ڷ�����ĳ�������������ںڵĽ����������ȴ�����Ե����ƣ�\n\n"NOR, ob, me);
           ob->add("force", -200);
           obj = all_inventory(environment(ob));
           if(sizeof(obj) > 1)
               message_vision(HIY"��Ȼ��������������֮���׷��Զ�Ծ��������$N��ǰ�ĵ��ϣ�����ָ�죡\n"NOR, ob);
           for(i=0; i<sizeof(obj); i++) {
                if(obj[i]==ob ) continue;
                inv = all_inventory(obj[i]);
                for(j= 0;j< sizeof(inv);j++){
                       if(!mapp(weapon_prop = inv[j]->query("weapon_prop"))) continue;        
                       if(inv[j]->query("skill_type")!="sword") continue;
                       if(inv[j]->query("equipped")){
                          if(obj[i]->query("force") > 5000){
                             obj[i]->add("force", -100);
                             tell_object(obj[i], HIW"���������֮"+inv[j]->name()+HIW"�������𶯣��Ҷ���˫�ֽ��գ���û�������ɳ���\n"NOR);
                             continue;  
                             }
                           else {
                                tell_object(obj[i], HIW"���������֮"+inv[j]->name()+HIW"�������𶯣�����ղ�ס����Ȼ���ַɳ���\n"NOR);
                                tell_room(environment(ob), YEL+obj[i]->name()+"һ�����ղ�ס������"+inv[j]->name()+YEL"��Ȼ���ַɳ���\n"NOR,({ obj[i] }));
                                }
                           }
                       inv[j]->move(environment(ob));
                       }
           }
           return ret;
       }
}

