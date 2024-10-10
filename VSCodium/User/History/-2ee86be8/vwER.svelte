<script lang="ts">
	import { OpenNewWindowIcon } from '@indaco/svelte-iconoir/open-new-window';

	let profiles = [
		{
			platform: 'CodeForces',
			link: 'https://codeforces.com/profile/pruh',
			username: 'pruh'
		},
		{
			platform: 'CodeChef',
			link: 'https://www.codechef.com/users/pruh',
			username: 'pruh'
		},
		{
			platform: 'AtCoder',
			link: 'https://atcoder.jp/users/pruh',
			username: 'pruh'
		},
		{
			platform: 'Leetcode',
			link: 'https://leetcode.com/u/pruh/',
			username: 'pruh'
		}
	];
</script>

<section class="wrapper" id="code">
	<div class="title">
		<h2><span>code</span>:work</h2>
	</div>
	<div class="grid">
		{#each profiles as { link, username, platform }}
			<a href={link} target="_blank" rel="noreferrer">
				<div class="profile-card">
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
		min-height: 140px;
		height: 100%;
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
		flex-direction: column;
		justify-content: center;
		align-items: center;
		display: grid;
		grid-template-columns: 1fr 1fr;
		margin-bottom: 3rem;
		position: relative;

		&:before {
			@include outlineText($content: 'λ', $translateX: 1150%, $translateY: -30%);
		}

		@media (max-width: 600px) {
			grid-template-columns: 1fr;
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