/*************************************************************************

    Act Fancer

*************************************************************************/

class actfancr_state : public driver_device
{
public:
	actfancr_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag),
		m_main_ram(*this, "main_ram"),
		m_maincpu(*this, "maincpu"),
		m_audiocpu(*this, "audiocpu"){ }

	/* memory pointers */
	required_shared_ptr<UINT8> m_main_ram;
	UINT16 m_spriteram16[0x800/2]; // a 16-bit copy of spriteram for use with the MXC06 code

	/* video-related */
	int                 m_flipscreen;

	/* misc */
	int            m_trio_control_select;

	/* devices */
	required_device<cpu_device> m_maincpu;
	required_device<cpu_device> m_audiocpu;
	DECLARE_WRITE8_MEMBER(triothep_control_select_w);
	DECLARE_READ8_MEMBER(triothep_control_r);
	DECLARE_WRITE8_MEMBER(actfancr_sound_w);
	DECLARE_WRITE8_MEMBER(actfancr_buffer_spriteram_w);
	virtual void video_start();
	DECLARE_MACHINE_START(actfancr);
	DECLARE_MACHINE_RESET(actfancr);
	DECLARE_MACHINE_START(triothep);
	DECLARE_MACHINE_RESET(triothep);
	UINT32 screen_update_actfancr(screen_device &screen, bitmap_ind16 &bitmap, const rectangle &cliprect);
	void register_savestate(  );
	DECLARE_WRITE_LINE_MEMBER(sound_irq);
};
