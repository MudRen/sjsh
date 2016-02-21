// channeld.c
// modified by tool on 96/10/05
// modified by mon@xyj on 10/97 to add support for
//          intermud emote.
// modified by vikee for xlqy on 2000.11
#include <ansi.h>
#include <net/dns.h>
#include <net/macros.h>
inherit F_DBASE;

#define REMOTE_Q    "/adm/daemons/network/services/remote_q.c"
// tomcat �޸�
// ��������Ƶ�� new
// ����Ƶ����mud_age����



mapping channels = ([
 "sys":  ([      "msg_speak": HIR "��"+HIW"ϵͳ"+HIR"��"+BLK"%s��%s\n" NOR, "wiz_only": 1 ]),
        "wiz":  ([      "msg_speak": HIY "����ʦ��%s��%s\n" NOR,
                                "msg_emote": HIY "����ʦ��%s\n" NOR,
                                "wiz_only": 1
                        ]),
        "gwiz": ([      "msg_speak": HIG "��������ʦ��%s��%s\n" NOR,
                                "msg_emote": HIG "��������ʦ��%s\n" NOR,
                                "wiz_only": 1, "intermud": GWIZ, "channel": "CREATOR",
                                "filter": 1,
                                 ]),
        "xyj":  ([      "msg_speak": HIR "���������Ρ�%s��%s\n" NOR,
                                "msg_emote": HIR "���������Ρ�%s\n" NOR,
                                "intermud": GCHANNEL, "channel": "xyj",
                                "filter": (:$1["MUDLIB"]=="A Journey to the West" :) ]),
        "es":   ([      "msg_speak": HIR "��"+HIW"̶������"+HIR"��"+HIW"%s��%s\n" NOR,
                                "msg_emote": HIR "��"+HIW"̶������"+HIR"��"+HIW"%s\n" NOR,
                                "intermud": GCHANNEL, "channel": "es",
                                "filter": 1 ]), //keep the channel name
                                //as "es" to be compatible with other
                                //ES2 type muds.
        "sldh": ([      "msg_speak": HIC "��ˮ½��᡿%s��%s\n" NOR,
                                "msg_emote": HIC "��ˮ½��᡿%s\n" NOR,
                         ]),

        "pk":   ([      "msg_speak": HIM "��������ս��%s��%s\n" NOR,
                                "msg_emote": HIM "��������ս��%s\n" NOR,
                         ]),
        "debug":([  "msg_speak": HIW "�����ԡ�%s��%s\n" NOR,
		"msg_emote": HIY "�����ԡ�%s" NOR,
		"wiz_only": 1,
	]),

        "chat": ([      "msg_speak": HIC "��"+HIG"̸��˵��"+HIC"��%s��%s\n" NOR,
                                "msg_emote": HIC "��"+HIG"̸��˵��"+HIC"��%s\n" NOR,
                    "intermud":GCHANNEL,"channel":"chat",
                    "chat_new" : 1
                         ]),
         "job": ([      "msg_speak": HIY "��"+HIC"������"+HIY"��"+HIG"%s��%s\n" NOR,
                                "msg_emote": HIY "��"+HIC"������"+HIY"��"+HIG"%s\n" NOR,
                         "intermud":GCHANNEL,"channel":"job"
                         ]),
        "rumor":([      "msg_speak": HIG "��"+HIR"������"+HIG"��"+HIM"%s��%s\n" NOR,
                                "msg_emote": HIC "��"+HIR"������"+HIG"��"+HIM"%s\n" NOR,
                                "anonymous": "ĳ��",
                         "intermud":GCHANNEL,"channel":"rumor"
                        ]),
        "music":([      "msg_speak": MAG "�������ָ���%s���ţ�%s\n" NOR,
                         ]),
    "club":([  "msg_speak": HIW "�����ɡ�%s��%s\n" NOR,
            "msg_emote": HIW "�����ɡ�%s\n" NOR,
            "msg_color": HIW,
            "party_only": 1 ]), 

/*   ������"club": ([      "msg_speak": HIB "�����ɡ�%s��%s\n" NOR,
                                "msg_emote": HIB "�����ɡ�%s" NOR,
                                "msg_color": HIB,
                                "party_only": 1 ]),
*/
        "new": ([        "msg_speak": HIR "��"HIB"����է��"HIR"��"HIG"%s��%s\n" NOR,
                                "msg_emote":  HIR "��"HIB"����է��"HIR"��"HIG"%s\n" NOR,

                          ]),

        "mp":  ([      "msg_speak": HIY "�����ɡ�"+HIG"%s: %s\n" NOR,
                                  "msg_emote": HIY "�����ɡ�"+HIG"%s\n" NOR,
                                 "msg_color": NOR+HIY,
                                 "menpai_only": 1 ]),

   "friendtalk":([ "msg_speak": HBMAG "��������ѡ�%s: %s\n" NOR,
                "msg_emote": HBMAG "��������ѡ�%s\n" NOR,
                "msg_color": NOR+HBMAG,
                "intermud":GCHANNEL,"channel":"friendtalk",
                "friend_only": 1 ]),
]);
string party;
string menpai;
void add_rumor(object me,string msg);
//yudian
int is_friend(object me);

void create()
{
        seteuid(getuid());      // This is required to pass intermud access check.
        set("channel_id", "Ƶ������");
        this_object()->set("rumor_point",0);
}

varargs int do_channel(object me, string verb, string arg, int emote,
        int allow_chat)
{
//yudian
        object *ob,*target;
        int i;
        string ob_id;
        mapping friends;

        string *tuned_ch, who, arg1;
        int time,count,count1,last_chat,len;

        // Check if this is a channel emote.
        if(sizeof(verb)>0)
           if( verb[sizeof(verb)-1] == '*' ) {
                emote = 1;
                verb = verb[0..<2];
        }
        
        // mon 10/29/98
        // ignore too long messages to reduce flooding.
        if(arg && strlen(arg)>240) return 0;

        if( !mapp(channels) || undefinedp(channels[verb]) )
                return 0;


        if( userp(me) && !allow_chat ) {
                if(channels[verb]["wiz_only"] && !wizardp(me) )
                        return 0;
//yudian
       if(channels[verb]["friend_only"]) {
        friends = me->query("friends");
        if(!friends
        || !mapp(friends)
        || (sizeof(friends) == 0))
                return notify_fail("��û���κε����ѣ�\n");
    }        

        if(channels[verb]["party_only"] && !me->query("club"))
                return notify_fail("�㻹���ȼ���һ��������˵�ɡ�\n");

        if (channels[verb]["party_only"]) {
                party = me->query("club");
                channels[verb]["msg_speak"] = HIY "��"+party+"��%s��%s\n" NOR;

        channels[verb]["msg_emote"] = HIY "��"+party+"��%s\n" NOR;

        }
         
         if (channels[verb]["menpai_only"] && !me->query("family/family_name"))
              return notify_fail("�����ĸ����ɵġ�\n");
          
          if (channels[verb]["menpai_only"]) {
       menpai = me->query("family/family_name");
channels[verb]["msg_speak"] = HIG "��"HIR+menpai+HIG"��%s��%s\n" NOR;
channels[verb]["msg_emote"] = HIG "��"HIR+menpai+HIG"��%s\n" NOR;
}
    // check if this channel support emote message. 
    if( emote && undefinedp(channels[verb]["msg_emote"])  ) {
        write("�Բ������Ƶ����֧�� emote ��\n");
        return 1;
    }

                //temporary block chat flooding.
                time=time();
                if(me->query("channel/chat_block") &&
                  (time-me->query("channel/chat_block"))<0 )
                   return notify_fail("��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");
              
                count=me->query("channel/chat_count");
                // if the channel arg contains too many lines,
                // then count more than once. -- mon 8/16/98
                count1=sizeof(explode(" "+arg,"\n"))/3+1;
                // if arg too long, also counts more.
                count1+=sizeof(arg)/200;
                count+=count1;
                last_chat=me->query("channel/last_chat");
                if (count>2) {
                  count=0;
                  me->set("channel/last_chat",time);
                  if (time==last_chat || count1>2) {
                    me->set("channel/chat_block",time+180);
                    return notify_fail("��Ϊһ�ν���̫�࣬��Ľ�̸Ƶ������ʱ�ر��ˡ�\n");
                  }
                }
                me->set("channel/chat_count",count);

                if( arg==(string)me->query_temp("last_channel_msg") )
                        return notify_fail("�ý�̸Ƶ��˵���벻Ҫ�ظ���ͬ��ѶϢ��\n");
                if (channels[verb]["chat_new"])
           {
               switch(me->query("class"))
                { 
                        case "dragon":
                        channels[verb]["msg_speak"] = WHT "��"HIG"��������"WHT"��"HIC"%s��%s\n" NOR;
                        break;
                        case "xian":
                        channels[verb]["msg_speak"] = WHT "��"HIG"���챱��"WHT"��"HIC"%s��%s\n" NOR;
                        break;
                        case "bonze":
                        channels[verb]["msg_speak"] = WHT "��"HIG"����Ĳ��"WHT"��"HIC"%s��%s\n" NOR;

                        break;
                        case "yaomo":
                        channels[verb]["msg_speak"] = WHT "��"HIG"��ħ���"WHT"��"HIC"%s��%s\n" NOR;
                        break;
                        case "swordsman":
                        channels[verb]["msg_speak"] = WHT "��"HIG"�������"WHT"��"HIC"%s��%s\n" NOR;
                        break;
                        case "taoist":
                        break;
                        case "youling":           
                        channels[verb]["msg_speak"] = WHT "��"HIG"ʮ�˵���"WHT"��"HIC"%s��%s\n" NOR;
                        break;
                        case "scholar":
                        case "fighter": 
                        channels[verb]["msg_speak"] = WHT "��"HIG"����Ԫ˧"WHT"��"HIC"%s��%s\n" NOR;
                        break;
                        case "wiz": 
                        channels[verb]["msg_speak"] = WHT "��"HBRED HIW"��    ��"NOR""WHT"��"HIC"%s��%s\n" NOR;
                        break;
                        default:
                               channels[verb]["msg_speak"] = WHT "��"HIG"̸��˵��"WHT"��"HIC"%s��%s\n" NOR;
                               break;
                }                 
            }
                // If we speaks something in this channel, then must tune it in.
                tuned_ch = me->query("channels");
                if( !pointerp(tuned_ch) )
                        me->set("channels", ({ verb }) );
                else if( member_array(verb, tuned_ch)==-1 )
                        me->set("channels", tuned_ch + ({ verb }) );

                // Support of channel emote
                if( emote && !channels[verb]["intermud_emote"]) {
                        string vb, emote_arg;

                        if( nullp(arg) ) return 0;
                        if( sscanf(arg, "%s %s", vb, emote_arg)!= 2 ) {
                                vb = arg;
                                emote_arg = "";
                        }
                if( channels[verb]["anonymous"] )
                           arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 1);
                else {
                   arg = EMOTE_D->do_emote(me, vb, emote_arg, 1, 0,
                       !undefinedp(channels[verb]["intermud"]));
                   if(!arg) {
                      string id, site;
                      if(sscanf(emote_arg, "%s@%s", id, site)==2) {
                        int age=me->query("mud_age");
                        // prevent login  newbie to flood channels.
                        if(!wizardp(me)) {
                            if(age<600) return notify_fail(
                                    "�����ڻ�����ʹ�����Ƶ��,����ʹ�� new Ƶ����˵����\n");
                            else if(age<86400) {
                                if((int)me->query("sen")<30) return 
                                    notify_fail
                                        ("�����ھ����㣬����ʹ�����Ƶ����\n");
                                me->add("sen",-5);
                            }
                        }

                REMOTE_Q->send_remote_q(site, verb, me->query("id"), id, vb);
                write("��·ѶϢ���ͳ������Ժ�\n");

                return 1;
                      }
                   }
                }

                if( !arg ) return 0;
                }
        }

        // Make the identity of speaker.

        if( channels[verb]["anonymous"] ) {
                who = channels[verb]["anonymous"];
                if (userp(me)) {
                    if((int)me->query("sen")<50) return
                        notify_fail("���Ѿ�û�о���ɢ��ҥ���ˡ�\n");
                    me->add("sen",-5);
                  do_channel( this_object(), "sys", 
                    sprintf("ҥ�ԣ�%s(%s)��", me->name(1),me->query("id")));
                  
                }
        }
        else if( userp(me) || !stringp(who = me->query("channel_id")) ) {
                who = me->query("name");
                if(me->query("id")) 
                  who=who+"(" + capitalize(me->query("id")) + ")";
             }

        // Ok, now send the message to those people listening us.

        ob = filter_array( users(), "filter_listener", this_object(), channels[verb] );
        if( !arg ) arg = "������";

        len=strlen(arg);
        while(len>1 && arg[len-1]=='\n')
            arg=arg[0..((len--)-2)];
        //remove excessive return at the end. by mon 9/20/97

        if(userp(me)) arg1=replace_string(arg, "$N", me->name());
        else arg1=arg;

        if( emote ) {
                // Support of old behavier of intermud emote.
                if( channels[verb]["intermud_emote"] ) arg1 = who + " " + arg;
        }

        if( arrayp(channels[verb]["extra_listener"]) ) {
                channels[verb]["extra_listener"] -= ({ 0 });
                if( sizeof(channels[verb]["extra_listener"]) )
                        channels[verb]["extra_listener"]->relay_channel(me, verb, arg);
        }
        
        if( !undefinedp(channels[verb]["intermud"])
        &&      base_name(me) != channels[verb]["intermud"] ) {
          if(userp(me)) {
            int age=me->query("mud_age");

            arg=replace_string(arg, "$N", me->name()+"("+
                capitalize(me->query("id"))+"@"+Mud_name()+")",1);
            arg=replace_string(arg, "$N", me->name());

            // prevent login  newbie to flood channels.
            if(!wizardp(me)) {
              if(age<3600) return notify_fail(
                    "�����ڻ�����ʹ�����Ƶ����\n");
              else if(age<86400) {
                if((int)me->query("sen")<30) return 
                    notify_fail
                        ("�����ھ����㣬����ʹ�����Ƶ����\n");
                me->add("sen",-5);
              }
            }
          }
          channels[verb]["intermud"]->send_msg(
                channels[verb]["channel"], me->query("id"), 
                   me->name(1), arg, emote, channels[verb]["filter"] );
        }

        if( emote ) {
                message( "channel:" + verb,
                        sprintf( channels[verb]["msg_emote"], arg1 ), ob );
        } else
                message( "channel:" + verb,
                        sprintf( channels[verb]["msg_speak"], who, arg1 ), ob );

        if( userp(me) ) 
        {
                me->set_temp("last_channel_msg", arg);
        }
        if( channels[verb]["anonymous"] ) add_rumor(me,arg); 
        return 1;
}

int filter_listener(object ppl, mapping ch)
{
        // Don't bother those in the login limbo.
        if( !environment(ppl) ) return 0;

        if( ch["wiz_only"] ) return wizardp(ppl);
        //as followed add by vikee,only belong to the party & wizard can see these message
        if (ch["party_only"])
                return (wizardp(ppl)
                && (!ppl->query("env/party") || ppl->query("env/party")==party))
                || party == ppl->query("club"); 
         //as followed add by yesi,only belong to the menpai & wizard can see these message
         if (ch["menpai_only"])
                return (wizardp(ppl)
                || ppl->query("family/family_name")==menpai); 
         
          if (ch["friend_only"])
                return (is_friend(ppl)); 
                
        return 1;
}

int is_friend(object ob)
{
    object me;
        string id;
        string * ids;
        mapping friends;
        int i;
    me=this_player();

    id=ob->query("id");

    if (ob==me) return 1;
    if (wizardp(ob)) return 1;

        friends = me->query("friends");
        ids = keys(friends);
        for(i=0;i<sizeof(ids);i++)
        {
                if(id == ids[i])
                 return 1;
        }

        return 0;
}


void register_relay_channel(string channel)
{
        object ob;
        ob = previous_object();
        if( undefinedp(channels[channel]) || !ob) return;
        if( arrayp(channels[channel]["extra_listener"]) ) {
                if( member_array(ob, channels[channel]["extra_listener"]) >=0 ) return;
                channels[channel]["extra_listener"] += ({ ob });
        } else
                channels[channel]["extra_listener"] = ({ ob });
}

void add_rumor(object me,string msg)
{
        object ob=this_object();
        string msg_id;
        int i;
        int detect_chance;
        int rumor_point=ob->query("rumor_point");
        rumor_point++;
        if (rumor_point>10) rumor_point-=10;
        i=sizeof(msg_id);
        msg_id="rumor_msg_0";
        i=sizeof(msg_id);
        msg_id[i-1]+=rumor_point;
        ob->set(msg_id,msg);
        msg_id="rumor_id_0";
        i=sizeof(msg_id);
        msg_id[i-1]+=rumor_point;
        ob->set("rumor_point",rumor_point);
        detect_chance=31-(int)(me->query("daoxing")/33333);
        if (!userp(me) || wizardp(me) || random(100)>detect_chance)
         {
           ob->set(msg_id,"none");
           return;
         }
        ob->set(msg_id,me->query("name")+"("+me->query("id")+")");
        return;                 
}

string query_rumor_msg(int num)
{
        string msg_id;
        string msg;
        int i;
        msg_id="rumor_msg_0";
        i=sizeof(msg_id);
        msg_id[i-1]+=num;
        return this_object()->query(msg_id);
}
string query_rumor_id(int num)
{
        string msg_id;
        string msg;
        int i;
        msg_id="rumor_id_0";
        i=sizeof(msg_id);
        msg_id[i-1]+=num;
        return this_object()->query(msg_id);
}
