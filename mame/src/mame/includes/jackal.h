
#define MASTER_CLOCK         XTAL_18_432MHz
#define SOUND_CLOCK          XTAL_3_579545MHz



class jackal_state : public driver_device
{
public:
	jackal_state(const machine_config &mconfig, device_type type, const char *tag)
		: driver_device(mconfig, type, tag),
		m_videoctrl(*this, "videoctrl"),
		m_paletteram(*this, "paletteram"),
		m_mastercpu(*this, "master"),
		m_slavecpu(*this, "slave"){ }

	/* memory pointers */
	required_shared_ptr<UINT8> m_videoctrl;
	UINT8 *  m_scrollram;
	required_shared_ptr<UINT8> m_paletteram;

	/* video-related */
	tilemap_t  *m_bg_tilemap;

	/* misc */
	int      m_irq_enable;
	UINT8    *m_rambank;
	UINT8    *m_spritebank;

	/* devices */
	required_device<cpu_device> m_mastercpu;
	required_device<cpu_device> m_slavecpu;
	DECLARE_READ8_MEMBER(topgunbl_rotary_r);
	DECLARE_WRITE8_MEMBER(jackal_flipscreen_w);
	DECLARE_READ8_MEMBER(jackal_zram_r);
	DECLARE_READ8_MEMBER(jackal_voram_r);
	DECLARE_READ8_MEMBER(jackal_spriteram_r);
	DECLARE_WRITE8_MEMBER(jackal_rambank_w);
	DECLARE_WRITE8_MEMBER(jackal_zram_w);
	DECLARE_WRITE8_MEMBER(jackal_voram_w);
	DECLARE_WRITE8_MEMBER(jackal_spriteram_w);
	TILE_GET_INFO_MEMBER(get_bg_tile_info);
	virtual void machine_start();
	virtual void machine_reset();
	virtual void video_start();
	virtual void palette_init();
	UINT32 screen_update_jackal(screen_device &screen, bitmap_ind16 &bitmap, const rectangle &cliprect);
	INTERRUPT_GEN_MEMBER(jackal_interrupt);
	void set_pens(  );
	void jackal_mark_tile_dirty( int offset );
	void draw_background( bitmap_ind16 &bitmap, const rectangle &cliprect );
	void draw_sprites_region( bitmap_ind16 &bitmap, const rectangle &cliprect, const UINT8 *sram, int length, int bank );
	void draw_sprites( bitmap_ind16 &bitmap, const rectangle &cliprect );
};

/*----------- defined in video/jackal.c -----------*/
void jackal_mark_tile_dirty(running_machine &machine, int offset);
