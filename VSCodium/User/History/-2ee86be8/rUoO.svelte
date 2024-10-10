<script>
	import { OpenNewWindowIcon } from '@indaco/svelte-iconoir/open-new-window';
  
	let profiles = [
	  {
		platform: 'CodeForces',
		link: 'https://codeforces.com/profile/pruh',
		username: 'pruh',
		logo: 'https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/codeforces.svg'
	  },
	  {
      platform: 'CodeChef',
      link: 'https://www.codechef.com/users/pruh',
      username: 'pruh',
      // Instead of a direct link, we'll use a base64-encoded image:
      logo: 'data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHZpZXdCb3g9IjAgMCAyNTYgMjU2Ij48cGF0aCBkPSJNMjIuNyA3LjljLTI3LjEgMC00OS4xIDIyLjEtNDkuMSA0OS4ydjY2LjFjMCAyNy4xIDIyLjEgNDkuMiA0OS4xIDQ5LjIgMzkuNCAwIDcyLjItMzIuOCA3Mi4yLTcyLjJ2LTY2LjFjMC0yNy4xLTIyLjgtNDkuMi00OS40LTQ5LjJ6bTAgNDAuOWM3LjQgMCAxMy40IDYgMTMuNCAxMy40IDAgNy40LTYgMTMuNC0xMy40IDEzLjQtNy40IDAtMTMuNC02LTEzLjQtMTMuNCAwLTcuNCA2LTEzLjQgMTMuNC0xMy40ek0xMjggNDhjLTM5LjQgMC03Mi4yIDMyLjgtNzIuMiA3Mi4ydiY2LjFjMCAyNy4xIDIyIDQ5LjIgNDkgNDkuMiAyNy40IDAgNDkuNC0yMi4xIDQ5LjQtNDkuMnYtNjYuMWMwLTI3LjEtMjIuMS00OS4yLTQ5LjQtNDkuMnoiIGZpbGw9IiNmNDgwMjMiLz48L3N2Zz4='  

    },
	  {
		platform: 'AtCoder',
		link: 'https://atcoder.jp/users/pruh',
		username: 'pruh',
		// Corrected AtCoder logo:
		logo: 'https://img.atcoder.jp/assets/atcoder.png' 
	  },
	  {
		platform: 'Leetcode',
		link: 'https://leetcode.com/u/pruh/',
		username: 'pruh',
		logo: 'https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/leet-code.svg'
	  }
	];
  </script>
  
  <section class="wrapper" id="code">
	<div class="title">
	  <h2><span>code</span>:work</h2>
	</div>
	<div class="grid">
	  {#each profiles as { link, username, platform, logo }}
		<a href={link} target="_blank" rel="noreferrer">
		  <div class="profile-card">
			<img src={logo} alt={platform} id="logo" />
			<div id="top-part">
			  <div class="info">
				<h6>{platform}</h6>
			  </div>
			  <div id="open">
				<OpenNewWindowIcon color="var(--text-secondary)" size="20px" />
			  </div>
			</div>
			<div>
			  <h3>{username}</h3>
			</div>
		  </div>
		</a>
	  {/each}
	</div>
  </section>
  
  <style lang="scss">
	@import '../../styles/mixins.scss';
  
	.title {
	  display: flex;
	  justify-content: center;
	  margin-top: 0;
  
	  @media (max-width: 868px) {
		justify-content: left;
	  }
	}
  
	.profile-card {
	  padding: 1rem 1.25rem;
	  background-color: var(--elevation-two);
	  border-radius: 8px;
	  width: 150px;
	  height: 150px;
	  display: flex;
	  flex-direction: column;
	  gap: 0.25rem;
	  transition: transform 0.3s var(--bezier-one), box-shadow 0.3s var(--bezier-one);
	  justify-content: space-between;
	  backdrop-filter: blur(5px);
	  -webkit-backdrop-filter: blur(5px);
	  background-blend-mode: overlay;
	  border: 1px solid var(--elevation-four);
  
	  &:hover {
		transform: translateY(-2px);
		box-shadow: 0px 15px 25px -10px rgba(0, 0, 0, 0.25);
  
		#open {
		  filter: brightness(1.3);
		}
	  }
  
	  #logo {
		width: 100px; /* Adjust logo size as needed */
		height: 50px;
		display: block;
		margin-left: auto;
		margin-right: auto;
		width: 50%;
	  }
	}
  
	a {
	  text-decoration: none;
	  color: var(--text-primary);
	  height: 100%;
	  border-radius: 8px;
	}
  
	h2 {
	  display: inline-block;
	  margin-bottom: 1rem;
	}
  
	#top-part {
	  display: flex;
	  justify-content: space-between;
	}
  
	#open {
	  height: 20px;
	  transition: filter 0.3s var(--bezier-one);
	}
  
	span {
	  color: var(--accent);
	}
  
	.grid {
	  gap: 0.8rem;
	  flex-direction: row;
	  justify-content: center;
	  align-items: center;
	  display: flex;
	  margin-bottom: 3rem;
	  position: relative;
  
	  &:before {
		@include outlineText($content: 'λ', $translateX: 1150%, $translateY: -30%);
	  }
  
	  @media (max-width: 600px) {
		flex-direction: column; /* Stack cards vertically on smaller screens */
	  }
  
	  @media (max-width: 868px) {
		margin-bottom: 2rem;
	  }
	}
  
	.info {
	  display: flex;
	  gap: 0.2rem;
	  align-items: center;
  
	  &-container {
		display: flex;
		gap: 0.9rem;
	  }
	}
  </style>