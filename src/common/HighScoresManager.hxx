//============================================================================
//
//   SSSS    tt          lll  lll
//  SS  SS   tt           ll   ll
//  SS     tttttt  eeee   ll   ll   aaaa
//   SSSS    tt   ee  ee  ll   ll      aa
//      SS   tt   eeeeee  ll   ll   aaaaa  --  "An Atari 2600 VCS Emulator"
//  SS  SS   tt   ee      ll   ll  aa  aa
//   SSSS     ttt  eeeee llll llll  aaaaa
//
// Copyright (c) 1995-2020 by Bradford W. Mott, Stephen Anthony
// and the Stella Team
//
// See the file "License.txt" for information on usage and redistribution of
// this file, and for a DISCLAIMER OF ALL WARRANTIES.
//============================================================================

#ifndef HIGHSCORES_MANAGER_HXX
#define HIGHSCORES_MANAGER_HXX

class OSystem;

class HighScoresManager
{

public:
  static const uInt32 MAX_PLAYERS = 4;
  static const uInt32 MAX_SCORE_ADDR = 3;

  using ScoreAddresses = array<Int16, MAX_SCORE_ADDR>;
  using ScoresAddresses = array<ScoreAddresses, MAX_PLAYERS>;

  struct Formats {
    uInt32 numDigits;
    uInt32 trailingZeroes;
    bool scoreBCD;
    bool varsBCD;
    bool varsZeroBased;
  };

  struct Addresses {
    ScoresAddresses scoresAddr;
    uInt16 varsAddr;
    uInt16 playersAddr;
  };

  HighScoresManager(OSystem& osystem);
  virtual ~HighScoresManager() = default;

  /*
    Methods for returning high scores related variables
  */
  bool get(const Properties& props, uInt32& numPlayers, uInt32& numVariations,
           Formats& formats, Addresses& addresses) const;
  void set(Properties& props, uInt32 numPlayers, uInt32 numVariations,
           const Formats& formats, const Addresses& addresses) const;

  uInt32 numAddrBytes(Int32 digits, Int32 trailing) const;

  Int32 score(uInt32 player, uInt32 numAddrBytes, uInt32 trailingZeroes, bool isBCD,
              const ScoreAddresses& scoreAddr) const;

  // retrieve current values
  Int32 player() const;
  Int32 variation() const;
  Int32 score() const;

private:
  static const uInt32 MAX_VARIATIONS = 256;
  static const uInt32 DEFAULT_PLAYER = 1;
  static const uInt32 DEFAULT_VARIATION = 1;
  static const uInt32 DEFAULT_DIGITS = 4;
  static const uInt32 DEFAULT_TRAILING = 0;
  static const bool DEFAULT_SCORE_BCD = true;
  static const bool DEFAULT_VARS_BCD = true;
  static const bool DEFAULT_VARS_ZERO_BASED = false;
  static const bool DEFAULT_PLAYERS_ZERO_BASED = true;
  static const uInt32 DEFAULT_ADDRESS = 0;

private:
  uInt32 numVariations(const Properties& props) const;
  uInt32 numPlayers(const Properties& props) const;
  uInt16 varAddress(const Properties& props) const;
  uInt16 playerAddress(const Properties& props) const;
  uInt32 numDigits(const Properties& props) const;
  uInt32 trailingZeroes(const Properties& props) const;
  bool scoreBCD(const Properties& props) const;
  bool varBCD(const Properties& props) const;
  bool varZeroBased(const Properties& props) const;
  bool playerZeroBased(const Properties& props) const;

  uInt32 numAddrBytes(const Properties& props) const;

  Properties& properties(Properties& props) const;
  string getPropIdx(const Properties& props, PropType type, uInt32 idx = 0) const;
  Int16 peek(uInt16 addr) const;

private:
  // Reference to the osystem object
  OSystem& myOSystem;

private:
  // Following constructors and assignment operators not supported
  HighScoresManager() = delete;
  HighScoresManager(const HighScoresManager&) = delete;
  HighScoresManager(HighScoresManager&&) = delete;
  HighScoresManager& operator=(const HighScoresManager&) = delete;
  HighScoresManager& operator=(HighScoresManager&&) = delete;
};
#endif